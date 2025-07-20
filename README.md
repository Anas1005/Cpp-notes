# Vision Infra: Strategy Developer Overview

Welcome to the **Vision Infra System** — your base for writing plug-and-play HFT strategies.

This guide is for **Quant/Strategy Developers** to understand:

* How the system works
* How to write your strategy
* How to access market data, timers, instruments, subscribe and listen to events, etc.

---

## Core Modules

| Module              | Purpose                                                 |
| ------------------- | ------------------------------------------------------- |
| `Player`            | Central manager for all infra components                |
| `Universe`          | Holds all tradable instruments                          |
| `Instrument`        | Represents a single tradable security                   |
| `Quote/Book`        | Access to order book and market data                    |
| `EventManager`      | Pub/sub system for market/trade events                  |
| `Hulk`              | Time and timer management                               |
| `UnderlyingDetails` | Derivatives (futures/options) for an underlying         |
| `PredictorBase`     | Base class you must inherit from to write your strategy |

---

## High-Level Infra Flow

```mermaid
graph TD;
    A[Infra Startup] --> B[Universe/Player Init];
    B --> C[Strategy Registered (PredictorBase)];
    C --> D[EventManager Publishes Events];
    D --> E[Strategy Receives Events];
    E --> F[Strategy Queries Market Data];
    F --> G[Strategy Takes Actions];
```

---

## How to Plug In Your Strategy

### 1. Inherit `PredictorBase`

```cpp
class MyStrategy : public vision::base_types::PredictorBase {
public:
    void init(const nlohmann::json& config) override {
        // Initialization logic
    }

    void handleEvent(vision::EventType etype, const void* event) override {
        // Handle event logic
    }
};
```

### 2. Register Your Strategy

Follow infra registration instructions (usually via factory or config mapping).

### 3. Use Global Modules

```cpp
vision::base::player.universe();       // Get Universe
vision::base::player.eventManager();   // EventManager
vision::base::hulk;                    // Timer & time access
```

---

## Common Code Patterns

### Read Config in `init`

```cpp
void init(const nlohmann::json& config) override {
    int param = config.value("my_param", 42);
    std::string symbol = config.value("symbol", "RELIANCE");
}
```

### Subscribe to Events

```cpp
void init(const nlohmann::json& config) override {
    auto& em = vision::base::player.eventManager();
    em.subscribeEvent(vision::EventType::TBTNEW, this);
    em.subscribeEvent(vision::EventType::TBTMOD, this);
    em.subscribeEvent(vision::EventType::TRADE, this);
}
```

### Handle Events

```cpp
void handleEvent(vision::EventType etype, const void* event) override {
    if (etype == vision::EventType::TBTNEW) {
        auto* ev = reinterpret_cast<const vision::base::TBTNEWEvent*>(event);
        // handle TBTNEW
    } else if (etype == vision::EventType::TRADE) {
        auto* ev = reinterpret_cast<const vision::base::TradeEvent*>(event);
        // handle trade
    }
}
```

---

## Market Data Access

### 1. Access Instruments

```cpp
auto& universe = vision::base::player.universe();
auto* inst = universe.getInstrumentFromSymbol("RELIANCE");
auto* inst2 = universe.getInstrumentFromId(1234);
```

### 2. Access Order Book

```cpp
if (inst) {
    auto* quote = inst->quote();
    auto best_bid = quote->bestBid();
    auto best_ask = quote->bestAsk();

    const auto& bid_book = quote->bidBook();
    for (auto* lvl = bid_book.topLevel(); lvl; lvl = lvl->next()) {
        auto price = lvl->price();
        auto size = lvl->totalSize();
    }
}
```

### 3. Access Underlying Details

```cpp
const auto* ud = universe.getUnderlyingDetails(vision::Exchange::NSEFO, "RELIANCE");
if (ud) {
    for (const auto& fut : ud->getFutures()) {
        auto* inst = fut.fut_;
    }
    for (const auto& chain : ud->getOptionChains()) {
        for (const auto& pair : chain.opt_pairs_) {
            auto* call = pair.call_;
            auto* put = pair.put_;
        }
    }
    auto* call = ud->getCallOptionFromExpiryDateAndStrikePriceInDouble(expiry, strike);
}
```

---

## Time and Timers (Hulk)

```cpp
// Get local time
auto now = vision::base::hulk.localTime();

// Set timer
int id = vision::base::hulk.addDeadlineTimer(
    vision::datetime::second * 5,
    this,
    [](const boost::system::error_code&) {
        // Callback logic
    }
);
```

---

For more functionalities, refer to module-level header files (`*.hpp`) or internal READMEs.
