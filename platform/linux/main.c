#include <stdio.h>
#include "uds_core.h"

int main(void)
{
    const uint8_t req[] = { 0x10u, 0x01u };   /* DiagnosticSessionControl: default */
    uint8_t resp[8];
    size_t n = uds_process(req, sizeof req, resp, sizeof resp);

    printf("req : 10 01\nresp:");
    for (size_t i = 0u; i < n; i++) {
        printf(" %02X", resp[i]);
    }
    printf("\n");
    return (n == 3u) ? 0 : 1;   /* non-zero exit fails CI */
}
