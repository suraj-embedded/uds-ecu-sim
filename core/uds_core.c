#include "uds_core.h"

#define UDS_NEGATIVE_RESPONSE      0x7Fu
#define NRC_SERVICE_NOT_SUPPORTED  0x11u

size_t uds_process(const uint8_t *req, size_t req_len,
                   uint8_t *resp, size_t resp_max)
{
    if ((req == NULL) || (resp == NULL) || (req_len == 0u) || (resp_max < 3u)) {
        return 0u;
    }
    /* Day 1 stub: every service -> 7F <SID> 11 (serviceNotSupported) */
    resp[0] = UDS_NEGATIVE_RESPONSE;
    resp[1] = req[0];
    resp[2] = NRC_SERVICE_NOT_SUPPORTED;
    return 3u;
}
