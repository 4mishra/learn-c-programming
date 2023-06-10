#include <stdio.h>
#include <yaml.h>

int main() {
    // Initialize the YAML parser
    yaml_parser_t parser;
    yaml_event_t event;

    FILE *file = fopen("example.yaml", "rb");
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, file);

    // Parse the YAML document
    do {
        if (!yaml_parser_parse(&parser, &event)) {
            printf("Error parsing YAML\n");
            return 1;
        }

        // Process the parsed event
        if (event.type == YAML_SCALAR_EVENT) {
            printf("Scalar value: %s\n", event.data.scalar.value);
        }

        // Free the event resources
        yaml_event_delete(&event);
    } while (event.type != YAML_STREAM_END_EVENT);

    // Cleanup
    yaml_parser_delete(&parser);
    fclose(file);

    return 0;
}
