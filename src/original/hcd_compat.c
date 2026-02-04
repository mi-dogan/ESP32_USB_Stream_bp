/*
 * Compatibility shims for Arduino-ESP32 / ESP-IDF variations.
 *
 * Some Arduino core / ESP-IDF builds may not export certain HCD symbols even if
 * headers declare them. To keep this library linkable across versions, we
 * provide weak fallback implementations.
 *
 * These fallbacks are best-effort: when the real implementation exists in the
 * core, it will override these weak symbols.
 */

#include "esp_err.h"
#include "hcd.h"

// FIFO biasing is an optimization/tuning knob. If the core doesn't provide it,
// fallback to a no-op returning success.
__attribute__((weak)) esp_err_t hcd_port_set_fifo_bias(hcd_port_handle_t port_hdl, hcd_port_fifo_bias_t bias)
{
    (void)port_hdl;
    (void)bias;
    return ESP_OK;
}

