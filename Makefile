raylib_path = E:/Library/raylib/raylib
cc = E:/Library/raylib/mingw/bin/gcc.exe

src_path = ./src
bin_path = ./bin
resource_path = ./res
bin = v2

src = $(src_path)/*.c $(src_path)/v2/*.c
c_flags = $(raylib_path)/src/raylib.rc.data -w -s -static -O2 -Iexternal -DPLATFORM_DESKTOP
ld_flags = -lraylib -lopengl32 -lgdi32 -lwinmm 

build:
	@$(cc) -o $(bin_path)/$(bin) $(src) $(c_flags) $(ld_flags)
	@cp -a $(resource_path)/. $(bin_path)/
	@echo "successful build."
clean:
	@rm -r -f $(bin_path)
	@mkdir bin
	@echo "cleaned bin."
run:
	@cd $(bin_path); \
	./$(bin)
	@echo "process finished."