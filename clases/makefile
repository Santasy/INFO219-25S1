CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wno-unknown-pragmas

# Expecting these as arguments
file ?= 
prob ?= 
io_folder ?= "./io/"

binary := $(prob)
build_dir := $(CURDIR)
src := $(file)
pnum := $(subst p,,${prob})

.PHONY: all run clean

all:
ifeq ($(file),)
	$(error You must specify the file, e.g., make -f ../Makefile file=main.cpp prob=p1)
endif
ifeq ($(prob),)
	$(error You must specify the prob, e.g., make -f ../Makefile file=main.cpp prob=p1)
endif
	@echo "Compiling $(src) for problem $(prob)..."
	$(CXX) $(CXXFLAGS) $(src) -o $(binary).bin

run:
ifeq ($(prob),)
	$(error You must specify the prob to run, e.g., make -f ../Makefile prob=p1 run)
endif

	@inputs=$$(ls -r ${io_folder}input${pnum}*.txt 2>/dev/null); \
	if [ -z "$$inputs" ]; then \
		echo "No input files found for ${prob} in ${io_folder}."; \
	else \
		for infile in $$inputs; do \
			base=$$(basename $$infile .txt); \
			suffix=$${base#input}; \
			outfile="${io_folder}output$$suffix.txt"; \
			expfile="${io_folder}expected$$suffix.txt"; \
			echo "Running $(prob).bin with $$infile -> $$outfile"; \
			./$(prob).bin < $$infile > $$outfile; \
			if [ -f "$$expfile" ]; then \
				echo "=== Diff against $$expfile ==="; \
				diff -u $$expfile $$outfile && echo "OK!" || echo "❌ Mismatch!"; \
			else \
				echo "⚠️  Expected file $$expfile not found."; \
			fi; \
		done; \
	fi

clean:
	@rm -f p1 p2 p3
