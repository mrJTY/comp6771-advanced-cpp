test:
	bazel test graph_test

format:
	clang-format -i *.cpp && \
	clang-format -i *.h && \
	python2 ../../cpplint.py *.cpp

submit:
	give cs6771 graph graph.h graph.tpp graph_test.cpp

