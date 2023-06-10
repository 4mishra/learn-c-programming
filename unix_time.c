#include <stdio.h>
#include <time.h>

int main() {
  time_t unix_timestamps[] = {1685605852, 1685606344, 1685640908};  // Replace with your Unix timestamp
  int num_timestamps = sizeof(unix_timestamps) / sizeof(unix_timestamps[0]);

  char human_times[num_timestamps][20];

  for (int i=0; i< num_timestamps; i++) {
    struct tm *timeinfo = localtime(&unix_timestamps[i]);
    
    strftime(human_times[i], sizeof(human_times[i]), "%Y-%m-%d %H:%M:%S", timeinfo);
  }

  for (int i = 0; i<num_timestamps; ++i) {
    printf("%s\n", human_times[i]);
  }
  return 0;
}
