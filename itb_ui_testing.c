#include <unistd.h>

#include "itb_ui.h"
#define ITB_UI_IMPLEMENTATION
#include "itb_ui.h"

int main(void) {
    itb_ui_context ctx;
    if (itb_ui_start(&ctx)) {
        perror("start");
        return 1;
    }

    for (int i = 0; i < 1000; ++i) {
        itb_ui_box(&ctx, (i%20)+1, (i%100)+1, 10, 10);
        itb_ui_rcprintf(&ctx, (i%20)+1, (i%100)+1, L"<%d>", i);
        itb_ui_flip(&ctx);
        usleep(5000);
    }

    itb_ui_end(&ctx);
    return 0;
}
