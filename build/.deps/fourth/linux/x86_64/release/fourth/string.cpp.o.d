{
    files = {
        "fourth/string.cpp"
    },
    depfiles_gcc = "string.o: fourth/string.cpp fourth/string.hpp\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-std=c++17",
            "-Ifourth"
        }
    }
}