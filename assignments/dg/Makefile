test:
	bazel test graph_test

format:
	clang-format -i *.cpp && \
	clang-format -i *.h && \
	python2 ../../cpplint.py *.cpp
