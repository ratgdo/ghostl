# Using ghostl with ESP-IDF

This library now supports ESP-IDF in addition to Arduino framework.

## Installation

### Method 1: As ESP-IDF Component

1. Add ghostl to your project's components directory:
```bash
cd your_esp_idf_project
mkdir -p components
cd components
git clone https://github.com/dok-net/ghostl.git
```

### Method 2: Using IDF Component Registry

Add to your project's `idf_component.yml`:
```yaml
dependencies:
  ghostl:
    version: ">=1.0.1"
```

## Usage

Include the headers you need in your ESP-IDF project:

```cpp
#include "circular_queue.h"
#include "lfllist.h"
#include "task.h"
// etc...
```

## Example

See the `examples/esp_idf_example` directory for a complete ESP-IDF project example.

To build the example:
```bash
cd examples/esp_idf_example
idf.py set-target esp32  # or esp32s2, esp32s3, etc.
idf.py build
idf.py flash monitor
```

## Components Available

- Lock-free circular queues (`circular_queue.h`, `circular_queue_mp.h`)
- Lock-free linked list (`lfllist.h`)
- C++ coroutines support (`task.h`, `generator.h`)
- Async programming utilities (`async_queue.h`, `when_all.h`, `when_any.h`)
- Fast scheduler (`FastScheduler.h`)
- Delegate pattern implementation (`Delegate.h`, `MultiDelegate.h`)