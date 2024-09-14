#include <stdio.h>

#define IMPLEMENT_BUILD_C
#include "build.h"

#define CFLAGS  "-O3", "-Wall", "-ggdb"
#define COMMON_INCLUDE "-Icommon/"
#define VENDOR_INCLUDE "-Ivendor"
#define LIB_PATH "-Ldependencies/", "-Lbin/", "-L."
#define COMMON_LIB "-l:bin/libcommon.a -lm"
#define GLAD_LIB "-l:bin/libglad.a"

#if __UNIX__
#define GL_LIB "-l:dependencies/libglfw.so -lGL -lX11 -lpthread -lXrandr -lXi -ldl"
#elif __WIN32__
#define GL_LIB "-l:dependencies/libglfw3.a -lopengl32 -lgdi32 -lwinmm  -lpthread -ldl"
#endif

const char *source[] = {
	"Triangle",
	"TriangleWithEBO",
	"Test",
	"ShaderUniforms"
};

const size_t src_len = sizeof(source) / sizeof(source[0]);

void make_glad()
{
	const char *glad_source[] = {
		"vendor/glad/src/glad.c"
	};

	const char *lib = "bin/libglad.a";

	if (needs_recompilation(lib, glad_source, 1))
	{
		CMD(
				"gcc",
				CFLAGS,
				VENDOR_INCLUDE,
				"-c",
				"vendor/glad/src/glad.c",
				"-o",
				"bin/glad.o"
		);

		CMD(
				"ar",
				"rcs",
				"bin/libglad.a",
				"bin/glad.o"
		);

		CMD("rm", "bin/glad.o");
	}
}

void make_common()
{
	int count;
	char **files = get_files_from_directory("common/", &count);

	if (needs_recompilation("bin/libcommon.a", (const char**)files, count))
	{
		for (int i = 0; i < count; ++i)
		{
			char *file = files[i];
			size_t len = strlen(file);

			if (file[len - 1] == 'c')
			{
				CMD(
						"gcc",
						CFLAGS,
						COMMON_INCLUDE,
						VENDOR_INCLUDE,
						"-lm",
						"-c",
						file,
						"-o",
						writef("bin/%s.o", file)
				);
			}
		}

		CMD("ar", "rcs", "bin/libcommon.a", "bin/common/*.o");
	}
}

void make_source()
{
	for (size_t i = 0; i < src_len; ++i)
	{
		int count;
		char **files = get_files_from_directory(writef("%s/", source[i]), &count);

		if (needs_recompilation(writef("bin/%s", source[i]), (const char**)files, count))
		{
			CMD(
					"gcc",
					CFLAGS,
					join(' ', (const char**)files, count),
					writef("-I%s/", source[i]),
					VENDOR_INCLUDE,
					COMMON_INCLUDE,
					LIB_PATH,
					GLAD_LIB,
					COMMON_LIB,
					GL_LIB,
					"-o",
					writef("bin/%s", source[i])
			);
		}
	}
}

int main(int argc, char *argv[])
{
	make_glad();
	make_common();
	make_source();

	return 0;
}