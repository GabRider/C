# Run "make STUDENT=xyz" where xyz is the directory to run the tests for
EXES=joseph pointer_sort matrix_compute
TESTS=$(addprefix test_,$(EXES))
CHECK=./check_output
RM=/bin/rm -f

all: $(TESTS)

test_joseph: $(STUDENT)/joseph
	@echo "[1]-------------------------------------------------"
	@echo "Running $< tests..."
	@./$< 17 7 > $<.candidate
	@$(CHECK) $(notdir $<.ref) $<.candidate

test_pointer_sort: $(STUDENT)/pointer_sort
	@echo "[2]-------------------------------------------------"
	@echo "Running $< tests..."
	@./$< 51 86 -16 4 23 -13 77 -20 49 65 -38 27 41 0 -3 19 > $<.candidate
	@$(CHECK) $(notdir $<.ref) $<.candidate

# sed is used to leave one decimal zero otherwise diff won't work
test_matrix_compute: $(STUDENT)/matrix_compute
	@echo "[3]-------------------------------------------------"
	@echo "Running $< tests..."
	@echo "[3a] transpose"
	@./$< transpose mat_A_2_4.dat > $(STUDENT)/mat.trans.candidate
	@$(CHECK) mat_At_4_2.ref $(STUDENT)/mat.trans.candidate
	@echo "[3b] add"
	@./$< add mat_B_3_2.dat mat_C_3_2.dat > $(STUDENT)/mat.add.candidate
	@$(CHECK) mat_B_add_C_3_2.ref $(STUDENT)/mat.add.candidate
	@echo "[3c] multiply"
	@./$< mult mat_D_2_3.dat mat_E_3_2.dat > $(STUDENT)/mat.mul.candidate
	@$(CHECK) mat_E_mul_E_2_2.ref $(STUDENT)/mat.mul.candidate

clean:
	@$(RM) $(STUDENT)/$(EXES) $(STUDENT)/*.o $(STUDENT)/*.candidate
