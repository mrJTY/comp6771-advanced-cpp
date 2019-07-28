test:
	bazel test graph_test

format:
	clang-format -i graph.tpp graph_test.cpp && \
	clang-format -i graph.h && \
	python2 ../../cpplint.py graph.tpp graph_test.cpp graph.h

submit:
	give cs6771 graph graph.h graph.tpp graph_test.cpp

