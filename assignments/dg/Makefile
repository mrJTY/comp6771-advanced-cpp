test:
	bazel test graph_test

myclient:
	bazel run myclient

format:
	clang-format -i graph.cpp graph_test.cpp && \
	clang-format -i graph.h && \
	python2 ../../cpplint.py graph.cpp graph_test.cpp graph.h

submit:
	give cs6771 graph graph.h graph.cpp graph_test.cpp

