#include <libconfig.h>
#include <stdio.h>
#include <stdlib.h>
#define CONFIG_FILE "example.cfg"

int main() {
  config_t cfg;
  int port;
  double interval;
  const char *host;

  config_init(&cfg);

  if (!config_read_file(&cfg, CONFIG_FILE)) {
    fprintf(stderr, "failed to read config file %s\n", CONFIG_FILE);
    config_destroy(&cfg);
    return EXIT_FAILURE;
  }

  if (config_lookup_string(&cfg, "host", &host)) {
    printf("name: %s\n", host);
  } else {
    fprintf(stderr, "No 'host' setting in configuration file.\n");
  }

  if (config_lookup_int(&cfg, "port", &port)) {
    printf("port: %d\n", port);
  } else {
    fprintf(stderr, "No 'port' setting in configuration file.\n");
  }

  if (config_lookup_float(&cfg, "interval", &interval)) {
    printf("interval: %.1f\n", interval);
  } else {
    fprintf(stderr, "No 'interval' setting in configuration file.\n");
  }

  config_destroy(&cfg);

  return EXIT_SUCCESS;
}
