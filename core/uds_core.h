#ifndef UDS_CORE_H
#define UDS_CORE_H
#include <stdint.h>
#include <stddef.h>

/* Process one UDS request; write the response into resp.
 * Returns the response length in bytes (0 = no response). */
size_t uds_process(const uint8_t *req, size_t req_len,
                   uint8_t *resp, size_t resp_max);
#endif
