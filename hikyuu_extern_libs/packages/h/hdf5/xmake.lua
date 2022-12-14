package("hdf5")

    set_homepage("https://www.hdfgroup.org/solutions/hdf5/")
    set_description("High-performance data management and storage suite")
    set_license("BSD-3-Clause")

    if is_plat("windows") then
        add_urls("https://github.com/fasiondog/hikyuu/releases/download/1.1.9/hdf5-$(version)-win-x64.zip",
                 "https://gitee.com/fasiondog/hikyuu/attach_files/114376/download/hdf5-$(version)-win-x64.zip",
                 "https://gitee.com/fasiondog/hikyuu/attach_files/935347/download/hdf5-$(version)-win-x64.zip")
        add_versions("1.12.2", "a75935688b24b30343433606e4d7ee0f09c789f748856bd3cbfecb6159471cac")
        add_versions("1.10.4", "253b23baada1d9c86cb4424595eba366b6844c384a5e0aafebf0893a1148f25f")
    end

    on_load(function (package)
        package:add("defines", "H5_BUILT_AS_DYNAMIC_LIB")
    end)

    on_install("windows", function (package)
        os.cp("include", package:installdir())
        os.cp("lib", package:installdir())
        os.cp("bin", package:installdir())
    end)

