javac -cp .;antlrworks-1.4.3.jar Test.java
java -cp .;antlrworks-1.4.3.jar Test %1.bgf > "../../user/parser%1.h"
