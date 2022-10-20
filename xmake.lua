set_targetdir(".out")
add_includedirs("first")
add_includedirs("third")
add_includedirs("fourth")
add_includedirs("fourth-2")
if is_mode("debug")then
    add_cxxflags("-g")
end

target("first-three")
    set_kind("binary")
    set_languages("cxx17")
    add_files("first/three.cpp")

target("first-complex")
    set_kind("binary")
    set_languages("cxx17")
    add_files("first/complex.cpp")

target("second-delete")
    set_kind("binary")
    set_languages("cxx17")
    add_files("second/delete_key.cpp")

target("second-list")
    set_kind("binary")
    set_languages("cxx17")
    add_files("second/List.cpp")

target("third-10to2")
    set_kind("binary")
    set_languages("cxx17")
    add_files("third/10to2.cpp")

target("third-cal")
    set_kind("binary")
    set_languages("cxx17")
    add_files("third/calculate.cpp")
    add_includedirs("third")

target("fourth-1-string")
    set_kind("binary")
    set_languages("cxx17")
    add_files("fourth/string.cpp")

target("fourth-1-kmp")
    set_kind("binary")
    set_languages("cxx17")
    add_files("fourth/kmp.cpp")

target("fourth-2")
    set_kind("binary")
    set_languages("cxx17")
    add_files("fourth-2/string.cpp")