@all:
	mkdir -p build && cd build && cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 && cmake --build . -j $$(nproc --ignore=1)

mono:
	mkdir -p build && cd build && cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 && cmake --build .

test-cppunit: ./build/tests/cppunit/cppunit-tests
	./build/tests/cppunit/cppunit-tests

tests: test-cppunit

clean:
	rm -rf build
