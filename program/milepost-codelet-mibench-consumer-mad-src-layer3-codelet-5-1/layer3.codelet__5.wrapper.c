/* 
 Codelet from MILEPOST project: http://cTuning.org/project-milepost
 Updated by Grigori Fursin to work with Collective Mind Framework

 3 "./layer3.codelet__5.wrapper.c" 3 4
*/

#include <stdio.h>

int __astex_write_message(const char * format, ...);
int __astex_write_output(const char * format, ...);
void __astex_exit_on_error(const char * msg, int code, const char * additional_msg);
void * __astex_fopen(const char * name, const char * mode);
void * __astex_memalloc(long bytes);
void __astex_close_file(void * file);
void __astex_read_from_file(void * dest, long bytes, void * file);
int __astex_getenv_int(const char * var);
void * __astex_start_measure();
double __astex_stop_measure(void * _before);
typedef signed int  mad_fixed_t;
typedef mad_fixed_t  mad_sample_t;
void  astex_codelet__5(mad_fixed_t z[36], unsigned int block_type, const mad_fixed_t window_l[36], const mad_fixed_t window_s[12]);
int main(int argc, const char **argv)
{
  mad_fixed_t  *z;
  unsigned int  block_type = 3u;
  const mad_fixed_t  *window_l;
  const mad_fixed_t  *window_s;
  void * codelet_data_file_descriptor = (void *) 0;

#ifdef OPENME
  openme_init(NULL,NULL,NULL,0);
  openme_callback("PROGRAM_START", NULL);
#endif

  if (argc < 2)
    __astex_exit_on_error("Please specify data file in command-line.", 1, argv[0]);
  codelet_data_file_descriptor = __astex_fopen(argv[1], "rb");
  
  char * z__region_buffer = (char *) __astex_memalloc(144);
  __astex_write_message("Reading z value from %s\n", argv[1]);
  __astex_read_from_file(z__region_buffer, 144, codelet_data_file_descriptor);
  z = (mad_fixed_t *) (z__region_buffer + 0l);
  char * window_l__region_buffer = (char *) __astex_memalloc(144);
  __astex_write_message("Reading window_l value from %s\n", argv[1]);
  __astex_read_from_file(window_l__region_buffer, 144, codelet_data_file_descriptor);
  window_l = (const mad_fixed_t *) (window_l__region_buffer + 0l);
  char * window_s__region_buffer = (char *) __astex_memalloc(48);
  __astex_write_message("Reading window_s value from %s\n", argv[1]);
  __astex_read_from_file(window_s__region_buffer, 48, codelet_data_file_descriptor);
  window_s = (const mad_fixed_t *) (window_s__region_buffer + 0l);
  void * _astex_timeval_before = __astex_start_measure();
  int _astex_wrap_loop = __astex_getenv_int("CT_REPEAT_MAIN");
  if (! _astex_wrap_loop)
    _astex_wrap_loop = 1;

#ifdef OPENME
  openme_callback("KERNEL_START", NULL);
#endif

  while (_astex_wrap_loop > 0)
  {
    --_astex_wrap_loop;
  astex_codelet__5(z, block_type, window_l, window_s);

  }

#ifdef OPENME
  openme_callback("KERNEL_END", NULL);
#endif

  __astex_write_output("Total time: %lf\n", __astex_stop_measure(_astex_timeval_before));


#ifdef OPENME
  openme_callback("PROGRAM_END", NULL);
#endif

  return 0;
}

