#ifndef DEES_NDS_ICON_H
#define DEES_NDS_ICON_H

#include <cstdint>
#include <cstdio>

#include <string>

class nds_icon {
public:
    nds_icon(std::string path);

    uint32_t *icon() {
        return ico;
    }

private:
    uint32_t ico[32 * 32];
};

#endif //DEES_NDS_ICON_H
