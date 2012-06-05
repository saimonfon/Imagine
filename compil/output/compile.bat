javac -cp .;antlrworks-1.4.3.jar Test.java
java -cp .;antlrworks-1.4.3.jar Test %1 > "../../grammaire/parser%1.cpp"