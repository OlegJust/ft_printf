#include "includes/ft_printf.h"

int main() {
    ft_printf("Hello %s! Number: %d, Hex: %x, Ptr: %p\n", "World", 42, 255, &main);
    return 0;
}
