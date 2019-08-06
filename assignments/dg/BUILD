cc_library(
    name = "graph",
    hdrs = [
        "graph.h",
        "graph.tpp",
    ],
    deps = [],
)

cc_binary(
    name = "client",
    srcs = ["client1.cpp"],
    deps = [
        ":graph",
    ],
)

cc_binary(
    name = "myclient",
    srcs = ["myclient.cpp"],
    deps = [
        ":graph",
    ],
)

cc_test(
    name = "graph_test",
    srcs = ["graph_test.cpp"],
    deps = [
        ":graph",
        "//:catch",
    ],
)
