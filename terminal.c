#include <stdio.h>
#include <stdlib.h>
#include <vterm.h>
#include <vterm_keycodes.h>

void write_callback(const char *bytes, size_t len, void *user) {
    fwrite(bytes, 1, len, stdout);
}

int main() {
    VTerm *vterm = vterm_new(180, 24);
    vterm_set_utf8(vterm, 1);
    vterm_output_set_callback(vterm, write_callback, NULL);

    // Simulate input by sending key codes
    // vterm_keyboard_key(vterm, VTERM_KEY_ENTER, VTERM_MOD_NONE);

    char buffer[1024];
    int bytes_read;
    
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), stdin)) > 0) {
        vterm_input_write(vterm, buffer, bytes_read);
        vterm_screen_flush_damage(vterm_obtain_screen(vterm));
    }

    vterm_free(vterm);
    return 0;
}
