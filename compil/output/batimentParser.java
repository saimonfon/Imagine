// $ANTLR 3.4 C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g 2012-10-01 15:56:12

import java.util.LinkedList;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class batimentParser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "ADJ", "ADJEXT", "ADJINT", "BOOL", "EXPONENT", "FLOAT", "ID", "INT", "OP_COMP", "WS", "'#'", "'$'", "'('", "')'", "','", "'->'", "'.'", "';'", "'='", "'@'", "'^'", "'cluster'", "'cycle'", "'ensemble'", "'grammaire'", "'partieConnexe'", "'sequence'", "'{'", "'}'"
    };

    public static final int EOF=-1;
    public static final int T__14=14;
    public static final int T__15=15;
    public static final int T__16=16;
    public static final int T__17=17;
    public static final int T__18=18;
    public static final int T__19=19;
    public static final int T__20=20;
    public static final int T__21=21;
    public static final int T__22=22;
    public static final int T__23=23;
    public static final int T__24=24;
    public static final int T__25=25;
    public static final int T__26=26;
    public static final int T__27=27;
    public static final int T__28=28;
    public static final int T__29=29;
    public static final int T__30=30;
    public static final int T__31=31;
    public static final int T__32=32;
    public static final int ADJ=4;
    public static final int ADJEXT=5;
    public static final int ADJINT=6;
    public static final int BOOL=7;
    public static final int EXPONENT=8;
    public static final int FLOAT=9;
    public static final int ID=10;
    public static final int INT=11;
    public static final int OP_COMP=12;
    public static final int WS=13;

    // delegates
    public Parser[] getDelegates() {
        return new Parser[] {};
    }

    // delegators


    public batimentParser(TokenStream input) {
        this(input, new RecognizerSharedState());
    }
    public batimentParser(TokenStream input, RecognizerSharedState state) {
        super(input, state);
    }

    public String[] getTokenNames() { return batimentParser.tokenNames; }
    public String getGrammarFileName() { return "C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g"; }


    int n=0; //compteur pour les regles
    int n2=0; //compteur pour les membres droits
    int n3 = 0; //compteur pour les conditions et regles de calcul
    int n4=0; //compteur pour les opérateurs imbriqués



    // $ANTLR start "grammaire"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:15:1: grammaire : dinclude dnom= def_nom def_regles ;
    public final void grammaire() throws RecognitionException {
        String dnom =null;


        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:16:2: ( dinclude dnom= def_nom def_regles )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:16:4: dinclude dnom= def_nom def_regles
            {

            System.out.println("#ifndef "+dnom+"_header");
            System.out.println("#define "+dnom+"_header");
            System.out.println("#include \"../grammaire/Parser.h\"");
            System.out.println("#include <vector>");
            System.out.println("#include <string>");
            System.out.println("#include \"../grammaire/Regle.h\"");
            System.out.println("#include \"../grammaire/OperateurCycle.h\"");
            System.out.println("#include \"../grammaire/MembreStandard.h\"");
            System.out.println("#include \"../grammaire/OperateurSequence.h\"");
            System.out.println("#include \"../grammaire/OperateurCluster.h\"");
            System.out.println("#include \"../grammaire/OperateurEnsemble.h\"");
            System.out.println("#include \"../grammaire/OperateurPartieConnexe.h\"");
            System.out.println("#include \"../grammaire/condition/ConditionAdj.h\"");
            System.out.println("#include \"../grammaire/condition/ConditionAdj_Ext.h\"");
            System.out.println("#include \"../grammaire/condition/ConditionAdj_Int.h\"");
            System.out.println("#include \"../grammaire/condition/ConditionEgal.h\"");
            System.out.println("#include \"../grammaire/regles/CalculAttributs.h\"");
            System.out.println("#include \"../grammaire/attributs/Attribut.h\"");


            pushFollow(FOLLOW_dinclude_in_grammaire28);
            dinclude();

            state._fsp--;


            pushFollow(FOLLOW_def_nom_in_grammaire32);
            dnom=def_nom();

            state._fsp--;


            System.out.println("class Parser"+dnom+" : public Parser {");
            System.out.println("public:");
            	System.out.println("Parser"+dnom+"(){");

            pushFollow(FOLLOW_def_regles_in_grammaire37);
            def_regles();

            state._fsp--;



            	System.out.println("}};");
            	System.out.println("#endif");
            	

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "grammaire"



    // $ANTLR start "dinclude"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:46:1: dinclude : ( '#' i= ID )* ;
    public final void dinclude() throws RecognitionException {
        Token i=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:47:2: ( ( '#' i= ID )* )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:47:4: ( '#' i= ID )*
            {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:47:4: ( '#' i= ID )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( (LA1_0==14) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:47:5: '#' i= ID
            	    {
            	    match(input,14,FOLLOW_14_in_dinclude49); 

            	    i=(Token)match(input,ID,FOLLOW_ID_in_dinclude53); 

            	    System.out.println("#include \""+(i!=null?i.getText():null)+".h\"");

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "dinclude"



    // $ANTLR start "def_nom"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:49:1: def_nom returns [String nom] : 'grammaire' id= ID ;
    public final String def_nom() throws RecognitionException {
        String nom = null;


        Token id=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:49:29: ( 'grammaire' id= ID )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:49:31: 'grammaire' id= ID
            {
            match(input,28,FOLLOW_28_in_def_nom69); 

            id=(Token)match(input,ID,FOLLOW_ID_in_def_nom73); 

            nom= (id!=null?id.getText():null);

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return nom;
    }
    // $ANTLR end "def_nom"



    // $ANTLR start "def_regles"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:50:1: def_regles : ( regle )* ;
    public final void def_regles() throws RecognitionException {
        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:51:2: ( ( regle )* )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:51:4: ( regle )*
            {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:51:4: ( regle )*
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==ID) ) {
                    alt2=1;
                }


                switch (alt2) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:51:4: regle
            	    {
            	    pushFollow(FOLLOW_regle_in_def_regles84);
            	    regle();

            	    state._fsp--;


            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "def_regles"



    // $ANTLR start "regle"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:53:1: regle : i1= ID '->' membre_droit ( ',' membre_droit )* '{' (lc= liste_contraintes )? '}' ( '{' ( liste_calcul | '@' c= ID ) '}' )? ;
    public final void regle() throws RecognitionException {
        Token i1=null;
        Token c=null;
        List<String> lc =null;


        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:53:7: (i1= ID '->' membre_droit ( ',' membre_droit )* '{' (lc= liste_contraintes )? '}' ( '{' ( liste_calcul | '@' c= ID ) '}' )? )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:53:9: i1= ID '->' membre_droit ( ',' membre_droit )* '{' (lc= liste_contraintes )? '}' ( '{' ( liste_calcul | '@' c= ID ) '}' )?
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle96); 

            match(input,19,FOLLOW_19_in_regle98); 

            System.out.println("vector<MembreDroit*> v"+n+";");

            pushFollow(FOLLOW_membre_droit_in_regle107);
            membre_droit();

            state._fsp--;


            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:55:16: ( ',' membre_droit )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==18) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:55:17: ',' membre_droit
            	    {
            	    match(input,18,FOLLOW_18_in_regle110); 

            	    pushFollow(FOLLOW_membre_droit_in_regle112);
            	    membre_droit();

            	    state._fsp--;


            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            System.out.println("Regle* r"+n+" = new Regle(\""+(i1!=null?i1.getText():null)+"\",v"+n+");");System.out.println("ajouterRegle(r"+n+");");

            match(input,31,FOLLOW_31_in_regle122); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:57:7: (lc= liste_contraintes )?
            int alt4=2;
            int LA4_0 = input.LA(1);

            if ( ((LA4_0 >= ADJ && LA4_0 <= ADJINT)||(LA4_0 >= 15 && LA4_0 <= 16)||LA4_0==23) ) {
                alt4=1;
            }
            switch (alt4) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:57:8: lc= liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle129);
                    lc=liste_contraintes();

                    state._fsp--;


                    for(String s:lc) System.out.println("r"+n+"->"+s);

                    }
                    break;

            }


            match(input,32,FOLLOW_32_in_regle134); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:58:3: ( '{' ( liste_calcul | '@' c= ID ) '}' )?
            int alt6=2;
            int LA6_0 = input.LA(1);

            if ( (LA6_0==31) ) {
                alt6=1;
            }
            switch (alt6) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:58:4: '{' ( liste_calcul | '@' c= ID ) '}'
                    {
                    match(input,31,FOLLOW_31_in_regle139); 

                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:58:8: ( liste_calcul | '@' c= ID )
                    int alt5=2;
                    int LA5_0 = input.LA(1);

                    if ( (LA5_0==ID) ) {
                        alt5=1;
                    }
                    else if ( (LA5_0==23) ) {
                        alt5=2;
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 5, 0, input);

                        throw nvae;

                    }
                    switch (alt5) {
                        case 1 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:58:9: liste_calcul
                            {
                            pushFollow(FOLLOW_liste_calcul_in_regle142);
                            liste_calcul();

                            state._fsp--;


                            System.out.println("r"+n+"->calculAtt = new Calcul"+n3+"();");n3++;

                            }
                            break;
                        case 2 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:59:5: '@' c= ID
                            {
                            match(input,23,FOLLOW_23_in_regle150); 

                            c=(Token)match(input,ID,FOLLOW_ID_in_regle154); 

                            System.out.println("r"+n+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                            }
                            break;

                    }


                    match(input,32,FOLLOW_32_in_regle159); 

                    }
                    break;

            }


            n++;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "regle"



    // $ANTLR start "membre_droit"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:61:1: membre_droit : ( membreStandard | operateur );
    public final void membre_droit() throws RecognitionException {
        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:62:2: ( membreStandard | operateur )
            int alt7=2;
            int LA7_0 = input.LA(1);

            if ( (LA7_0==ID) ) {
                alt7=1;
            }
            else if ( ((LA7_0 >= 25 && LA7_0 <= 27)||(LA7_0 >= 29 && LA7_0 <= 30)) ) {
                alt7=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 7, 0, input);

                throw nvae;

            }
            switch (alt7) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:62:5: membreStandard
                    {
                    pushFollow(FOLLOW_membreStandard_in_membre_droit178);
                    membreStandard();

                    state._fsp--;


                    }
                    break;
                case 2 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:62:22: operateur
                    {
                    pushFollow(FOLLOW_operateur_in_membre_droit182);
                    operateur();

                    state._fsp--;


                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "membre_droit"



    // $ANTLR start "membreStandard"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:65:1: membreStandard : i2= ID ;
    public final void membreStandard() throws RecognitionException {
        Token i2=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:66:2: (i2= ID )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:66:5: i2= ID
            {
            i2=(Token)match(input,ID,FOLLOW_ID_in_membreStandard198); 

            System.out.println("v"+n+".push_back(new MembreStandard(\""+(i2!=null?i2.getText():null)+"\"));");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "membreStandard"



    // $ANTLR start "operateur"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:68:1: operateur : ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' ) '(' (i2= ID ( '{' contrainte_op_membres '}' )? | operateur_imbrique ) ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')' ;
    public final void operateur() throws RecognitionException {
        Token i2=null;
        Token c=null;
        List<String> lc =null;


        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:69:2: ( ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' ) '(' (i2= ID ( '{' contrainte_op_membres '}' )? | operateur_imbrique ) ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')' )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:69:4: ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' ) '(' (i2= ID ( '{' contrainte_op_membres '}' )? | operateur_imbrique ) ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')'
            {
            String opType="";

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:69:23: ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' )
            int alt8=5;
            switch ( input.LA(1) ) {
            case 30:
                {
                alt8=1;
                }
                break;
            case 26:
                {
                alt8=2;
                }
                break;
            case 25:
                {
                alt8=3;
                }
                break;
            case 27:
                {
                alt8=4;
                }
                break;
            case 29:
                {
                alt8=5;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 8, 0, input);

                throw nvae;

            }

            switch (alt8) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:69:24: 'sequence'
                    {
                    match(input,30,FOLLOW_30_in_operateur214); 

                    opType="OperateurSequence";

                    }
                    break;
                case 2 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:70:5: 'cycle'
                    {
                    match(input,26,FOLLOW_26_in_operateur222); 

                    opType="OperateurCycle";

                    }
                    break;
                case 3 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:71:4: 'cluster'
                    {
                    match(input,25,FOLLOW_25_in_operateur229); 

                    opType="OperateurCluster";

                    }
                    break;
                case 4 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:72:4: 'ensemble'
                    {
                    match(input,27,FOLLOW_27_in_operateur236); 

                    opType="OperateurEnsemble";

                    }
                    break;
                case 5 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:73:5: 'partieConnexe'
                    {
                    match(input,29,FOLLOW_29_in_operateur244); 

                    opType="OperateurPartieConnexe";

                    }
                    break;

            }


            match(input,16,FOLLOW_16_in_operateur251); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:75:3: (i2= ID ( '{' contrainte_op_membres '}' )? | operateur_imbrique )
            int alt10=2;
            int LA10_0 = input.LA(1);

            if ( (LA10_0==ID) ) {
                alt10=1;
            }
            else if ( ((LA10_0 >= 25 && LA10_0 <= 27)||(LA10_0 >= 29 && LA10_0 <= 30)) ) {
                alt10=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 10, 0, input);

                throw nvae;

            }
            switch (alt10) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:75:4: i2= ID ( '{' contrainte_op_membres '}' )?
                    {
                    i2=(Token)match(input,ID,FOLLOW_ID_in_operateur261); 

                    System.out.println(opType+"* op"+n2+"= new "+opType+"(\""+(i2!=null?i2.getText():null)+"\",\"OPE\");");

                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:75:98: ( '{' contrainte_op_membres '}' )?
                    int alt9=2;
                    int LA9_0 = input.LA(1);

                    if ( (LA9_0==31) ) {
                        alt9=1;
                    }
                    switch (alt9) {
                        case 1 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:75:99: '{' contrainte_op_membres '}'
                            {
                            match(input,31,FOLLOW_31_in_operateur266); 

                            pushFollow(FOLLOW_contrainte_op_membres_in_operateur268);
                            contrainte_op_membres();

                            state._fsp--;


                            match(input,32,FOLLOW_32_in_operateur270); 

                            }
                            break;

                    }


                    }
                    break;
                case 2 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:76:4: operateur_imbrique
                    {
                    pushFollow(FOLLOW_operateur_imbrique_in_operateur277);
                    operateur_imbrique();

                    state._fsp--;


                    System.out.println(opType+"* op"+n2+"= new "+opType+"(opi"+n4+",\"OPE_IMBRIQUE\");");n4++;

                    }
                    break;

            }


            match(input,18,FOLLOW_18_in_operateur284); 

            match(input,31,FOLLOW_31_in_operateur286); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:77:11: (lc= liste_contraintes )?
            int alt11=2;
            int LA11_0 = input.LA(1);

            if ( ((LA11_0 >= ADJ && LA11_0 <= ADJINT)||(LA11_0 >= 15 && LA11_0 <= 16)||LA11_0==23) ) {
                alt11=1;
            }
            switch (alt11) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:77:12: lc= liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_operateur293);
                    lc=liste_contraintes();

                    state._fsp--;


                    for(String s:lc) System.out.println("op"+n2+"->"+s);

                    }
                    break;

            }


            match(input,32,FOLLOW_32_in_operateur298); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:78:4: ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )?
            int alt13=2;
            int LA13_0 = input.LA(1);

            if ( (LA13_0==18) ) {
                alt13=1;
            }
            switch (alt13) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:78:5: ',' ( '{' liste_calcul | '@' c= ID ) '}'
                    {
                    match(input,18,FOLLOW_18_in_operateur304); 

                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:78:9: ( '{' liste_calcul | '@' c= ID )
                    int alt12=2;
                    int LA12_0 = input.LA(1);

                    if ( (LA12_0==31) ) {
                        alt12=1;
                    }
                    else if ( (LA12_0==23) ) {
                        alt12=2;
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 12, 0, input);

                        throw nvae;

                    }
                    switch (alt12) {
                        case 1 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:78:10: '{' liste_calcul
                            {
                            match(input,31,FOLLOW_31_in_operateur307); 

                            pushFollow(FOLLOW_liste_calcul_in_operateur309);
                            liste_calcul();

                            state._fsp--;


                            System.out.println("op"+n2+"->calculAtt = new Calcul"+n3+"();");n3++;

                            }
                            break;
                        case 2 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:79:4: '@' c= ID
                            {
                            match(input,23,FOLLOW_23_in_operateur316); 

                            c=(Token)match(input,ID,FOLLOW_ID_in_operateur320); 

                            System.out.println("op"+n2+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                            }
                            break;

                    }


                    match(input,32,FOLLOW_32_in_operateur325); 

                    }
                    break;

            }


            match(input,17,FOLLOW_17_in_operateur330); 

            System.out.println("v"+n+".push_back(op"+n2+");");n2++;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "operateur"



    // $ANTLR start "operateur_imbrique"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:81:3: operateur_imbrique : ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' ) '(' i2= ID ( '{' contrainte_op_membres_imbrique '}' )? ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')' ;
    public final void operateur_imbrique() throws RecognitionException {
        Token i2=null;
        Token c=null;
        List<String> lc =null;


        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:82:2: ( ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' ) '(' i2= ID ( '{' contrainte_op_membres_imbrique '}' )? ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')' )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:82:4: ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' ) '(' i2= ID ( '{' contrainte_op_membres_imbrique '}' )? ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')'
            {
            String opType="";

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:82:23: ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' | 'partieConnexe' )
            int alt14=5;
            switch ( input.LA(1) ) {
            case 30:
                {
                alt14=1;
                }
                break;
            case 26:
                {
                alt14=2;
                }
                break;
            case 25:
                {
                alt14=3;
                }
                break;
            case 27:
                {
                alt14=4;
                }
                break;
            case 29:
                {
                alt14=5;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 14, 0, input);

                throw nvae;

            }

            switch (alt14) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:82:24: 'sequence'
                    {
                    match(input,30,FOLLOW_30_in_operateur_imbrique348); 

                    opType="OperateurSequence";

                    }
                    break;
                case 2 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:83:5: 'cycle'
                    {
                    match(input,26,FOLLOW_26_in_operateur_imbrique356); 

                    opType="OperateurCycle";

                    }
                    break;
                case 3 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:84:4: 'cluster'
                    {
                    match(input,25,FOLLOW_25_in_operateur_imbrique363); 

                    opType="OperateurCluster";

                    }
                    break;
                case 4 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:85:4: 'ensemble'
                    {
                    match(input,27,FOLLOW_27_in_operateur_imbrique370); 

                    opType="OperateurEnsemble";

                    }
                    break;
                case 5 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:86:5: 'partieConnexe'
                    {
                    match(input,29,FOLLOW_29_in_operateur_imbrique378); 

                    opType="OperateurPartieConnexe";

                    }
                    break;

            }


            match(input,16,FOLLOW_16_in_operateur_imbrique385); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_operateur_imbrique391); 

            System.out.println(opType+"* opi"+n4+"= new "+opType+"(\""+(i2!=null?i2.getText():null)+"\",\"OPE\");");

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:87:102: ( '{' contrainte_op_membres_imbrique '}' )?
            int alt15=2;
            int LA15_0 = input.LA(1);

            if ( (LA15_0==31) ) {
                alt15=1;
            }
            switch (alt15) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:87:103: '{' contrainte_op_membres_imbrique '}'
                    {
                    match(input,31,FOLLOW_31_in_operateur_imbrique396); 

                    pushFollow(FOLLOW_contrainte_op_membres_imbrique_in_operateur_imbrique398);
                    contrainte_op_membres_imbrique();

                    state._fsp--;


                    match(input,32,FOLLOW_32_in_operateur_imbrique400); 

                    }
                    break;

            }


            match(input,18,FOLLOW_18_in_operateur_imbrique406); 

            match(input,31,FOLLOW_31_in_operateur_imbrique408); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:88:11: (lc= liste_contraintes )?
            int alt16=2;
            int LA16_0 = input.LA(1);

            if ( ((LA16_0 >= ADJ && LA16_0 <= ADJINT)||(LA16_0 >= 15 && LA16_0 <= 16)||LA16_0==23) ) {
                alt16=1;
            }
            switch (alt16) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:88:12: lc= liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_operateur_imbrique415);
                    lc=liste_contraintes();

                    state._fsp--;


                    for(String s:lc) System.out.println("opi"+n4+"->"+s);

                    }
                    break;

            }


            match(input,32,FOLLOW_32_in_operateur_imbrique420); 

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:89:4: ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )?
            int alt18=2;
            int LA18_0 = input.LA(1);

            if ( (LA18_0==18) ) {
                alt18=1;
            }
            switch (alt18) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:89:5: ',' ( '{' liste_calcul | '@' c= ID ) '}'
                    {
                    match(input,18,FOLLOW_18_in_operateur_imbrique426); 

                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:89:9: ( '{' liste_calcul | '@' c= ID )
                    int alt17=2;
                    int LA17_0 = input.LA(1);

                    if ( (LA17_0==31) ) {
                        alt17=1;
                    }
                    else if ( (LA17_0==23) ) {
                        alt17=2;
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 17, 0, input);

                        throw nvae;

                    }
                    switch (alt17) {
                        case 1 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:89:10: '{' liste_calcul
                            {
                            match(input,31,FOLLOW_31_in_operateur_imbrique429); 

                            pushFollow(FOLLOW_liste_calcul_in_operateur_imbrique431);
                            liste_calcul();

                            state._fsp--;


                            System.out.println("opi"+n4+"->calculAtt = new Calcul"+n3+"();");n3++;

                            }
                            break;
                        case 2 :
                            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:90:4: '@' c= ID
                            {
                            match(input,23,FOLLOW_23_in_operateur_imbrique438); 

                            c=(Token)match(input,ID,FOLLOW_ID_in_operateur_imbrique442); 

                            System.out.println("opi"+n4+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                            }
                            break;

                    }


                    match(input,32,FOLLOW_32_in_operateur_imbrique447); 

                    }
                    break;

            }


            match(input,17,FOLLOW_17_in_operateur_imbrique452); 

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "operateur_imbrique"



    // $ANTLR start "contrainte_op_membres"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:92:1: contrainte_op_membres : ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )* ;
    public final void contrainte_op_membres() throws RecognitionException {
        Token att=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:93:2: ( ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )* )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:93:4: ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )*
            {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:93:4: ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )*
            loop19:
            do {
                int alt19=2;
                int LA19_0 = input.LA(1);

                if ( (LA19_0==ADJ) ) {
                    alt19=1;
                }


                switch (alt19) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:93:5: ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')'
            	    {
            	    match(input,ADJ,FOLLOW_ADJ_in_contrainte_op_membres463); 

            	    match(input,16,FOLLOW_16_in_contrainte_op_membres465); 

            	    att=(Token)match(input,ID,FOLLOW_ID_in_contrainte_op_membres469); 

            	    match(input,18,FOLLOW_18_in_contrainte_op_membres471); 

            	    match(input,14,FOLLOW_14_in_contrainte_op_membres473); 

            	    j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_op_membres477); 

            	    match(input,20,FOLLOW_20_in_contrainte_op_membres479); 

            	    att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_op_membres483); 

            	    match(input,17,FOLLOW_17_in_contrainte_op_membres485); 

            	    System.out.println("op"+n2+"->condAdjExt.push_back(new ConditionAdj(0,\""+(att!=null?att.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

            	    }
            	    break;

            	default :
            	    break loop19;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "contrainte_op_membres"



    // $ANTLR start "contrainte_op_membres_imbrique"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:96:1: contrainte_op_membres_imbrique : ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )* ;
    public final void contrainte_op_membres_imbrique() throws RecognitionException {
        Token att=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:97:2: ( ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )* )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:97:4: ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )*
            {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:97:4: ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )*
            loop20:
            do {
                int alt20=2;
                int LA20_0 = input.LA(1);

                if ( (LA20_0==ADJ) ) {
                    alt20=1;
                }


                switch (alt20) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:97:5: ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')'
            	    {
            	    match(input,ADJ,FOLLOW_ADJ_in_contrainte_op_membres_imbrique501); 

            	    match(input,16,FOLLOW_16_in_contrainte_op_membres_imbrique503); 

            	    att=(Token)match(input,ID,FOLLOW_ID_in_contrainte_op_membres_imbrique507); 

            	    match(input,18,FOLLOW_18_in_contrainte_op_membres_imbrique509); 

            	    match(input,14,FOLLOW_14_in_contrainte_op_membres_imbrique511); 

            	    j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_op_membres_imbrique515); 

            	    match(input,20,FOLLOW_20_in_contrainte_op_membres_imbrique517); 

            	    att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_op_membres_imbrique521); 

            	    match(input,17,FOLLOW_17_in_contrainte_op_membres_imbrique523); 

            	    System.out.println("opi"+n4+"->condAdjExt.push_back(new ConditionAdj(0,\""+(att!=null?att.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

            	    }
            	    break;

            	default :
            	    break loop20;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "contrainte_op_membres_imbrique"



    // $ANTLR start "liste_contraintes"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:99:1: liste_contraintes returns [List<String> liste] :c= contrainte ( '^' c2= contrainte )* ;
    public final List<String> liste_contraintes() throws RecognitionException {
        List<String> liste = null;


        String c =null;

        String c2 =null;


        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:99:47: (c= contrainte ( '^' c2= contrainte )* )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:100:2: c= contrainte ( '^' c2= contrainte )*
            {
            liste = new LinkedList<String>();

            pushFollow(FOLLOW_contrainte_in_liste_contraintes544);
            c=contrainte();

            state._fsp--;


            liste.add(c);

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:100:76: ( '^' c2= contrainte )*
            loop21:
            do {
                int alt21=2;
                int LA21_0 = input.LA(1);

                if ( (LA21_0==24) ) {
                    alt21=1;
                }


                switch (alt21) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:100:77: '^' c2= contrainte
            	    {
            	    match(input,24,FOLLOW_24_in_liste_contraintes548); 

            	    pushFollow(FOLLOW_contrainte_in_liste_contraintes552);
            	    c2=contrainte();

            	    state._fsp--;


            	    liste.add(c2);

            	    }
            	    break;

            	default :
            	    break loop21;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return liste;
    }
    // $ANTLR end "liste_contraintes"



    // $ANTLR start "liste_calcul"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:102:1: liste_calcul : ( expr_calcul ';' )+ ;
    public final void liste_calcul() throws RecognitionException {
        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:103:2: ( ( expr_calcul ';' )+ )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:104:2: ( expr_calcul ';' )+
            {
             System.out.println("class Calcul"+n3+" : public CalculAttributs {");System.out.println("void calculAttrib(Noeud* nouveau){");

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:105:2: ( expr_calcul ';' )+
            int cnt22=0;
            loop22:
            do {
                int alt22=2;
                int LA22_0 = input.LA(1);

                if ( (LA22_0==ID) ) {
                    alt22=1;
                }


                switch (alt22) {
            	case 1 :
            	    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:105:3: expr_calcul ';'
            	    {
            	    pushFollow(FOLLOW_expr_calcul_in_liste_calcul571);
            	    expr_calcul();

            	    state._fsp--;


            	    match(input,21,FOLLOW_21_in_liste_calcul573); 

            	    }
            	    break;

            	default :
            	    if ( cnt22 >= 1 ) break loop22;
                        EarlyExitException eee =
                            new EarlyExitException(22, input);
                        throw eee;
                }
                cnt22++;
            } while (true);


            System.out.println("}};");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "liste_calcul"



    // $ANTLR start "contrainte"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:107:2: contrainte returns [String toString] : (c= contrainte_egal |c= contrainte_adj |c= contrainte_adj_ext |c= contrainte_adj_int |c= condition_unique |c= contrainte_generale | '(' c= contrainte ')' );
    public final String contrainte() throws RecognitionException {
        String toString = null;


        String c =null;


        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:107:38: (c= contrainte_egal |c= contrainte_adj |c= contrainte_adj_ext |c= contrainte_adj_int |c= condition_unique |c= contrainte_generale | '(' c= contrainte ')' )
            int alt23=7;
            switch ( input.LA(1) ) {
            case 15:
                {
                int LA23_1 = input.LA(2);

                if ( (LA23_1==INT) ) {
                    int LA23_7 = input.LA(3);

                    if ( (LA23_7==20) ) {
                        int LA23_8 = input.LA(4);

                        if ( (LA23_8==ID) ) {
                            int LA23_9 = input.LA(5);

                            if ( (LA23_9==22) ) {
                                alt23=1;
                            }
                            else if ( (LA23_9==OP_COMP) ) {
                                alt23=5;
                            }
                            else {
                                NoViableAltException nvae =
                                    new NoViableAltException("", 23, 9, input);

                                throw nvae;

                            }
                        }
                        else {
                            NoViableAltException nvae =
                                new NoViableAltException("", 23, 8, input);

                            throw nvae;

                        }
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 23, 7, input);

                        throw nvae;

                    }
                }
                else {
                    NoViableAltException nvae =
                        new NoViableAltException("", 23, 1, input);

                    throw nvae;

                }
                }
                break;
            case ADJ:
                {
                alt23=2;
                }
                break;
            case ADJEXT:
                {
                alt23=3;
                }
                break;
            case ADJINT:
                {
                alt23=4;
                }
                break;
            case 23:
                {
                alt23=6;
                }
                break;
            case 16:
                {
                alt23=7;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 23, 0, input);

                throw nvae;

            }

            switch (alt23) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:108:2: c= contrainte_egal
                    {
                    pushFollow(FOLLOW_contrainte_egal_in_contrainte593);
                    c=contrainte_egal();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 2 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:109:2: c= contrainte_adj
                    {
                    pushFollow(FOLLOW_contrainte_adj_in_contrainte601);
                    c=contrainte_adj();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 3 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:110:2: c= contrainte_adj_ext
                    {
                    pushFollow(FOLLOW_contrainte_adj_ext_in_contrainte609);
                    c=contrainte_adj_ext();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 4 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:111:2: c= contrainte_adj_int
                    {
                    pushFollow(FOLLOW_contrainte_adj_int_in_contrainte616);
                    c=contrainte_adj_int();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 5 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:112:2: c= condition_unique
                    {
                    pushFollow(FOLLOW_condition_unique_in_contrainte623);
                    c=condition_unique();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 6 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:113:2: c= contrainte_generale
                    {
                    pushFollow(FOLLOW_contrainte_generale_in_contrainte631);
                    c=contrainte_generale();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 7 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:114:2: '(' c= contrainte ')'
                    {
                    match(input,16,FOLLOW_16_in_contrainte637); 

                    pushFollow(FOLLOW_contrainte_in_contrainte641);
                    c=contrainte();

                    state._fsp--;


                    toString = c;

                    match(input,17,FOLLOW_17_in_contrainte644); 

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "contrainte"



    // $ANTLR start "contrainte_egal"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:116:2: contrainte_egal returns [String toString] : '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final String contrainte_egal() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:116:43: ( '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:116:45: '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            match(input,15,FOLLOW_15_in_contrainte_egal657); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal661); 

            match(input,20,FOLLOW_20_in_contrainte_egal663); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal667); 

            match(input,22,FOLLOW_22_in_contrainte_egal669); 

            match(input,15,FOLLOW_15_in_contrainte_egal671); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal675); 

            match(input,20,FOLLOW_20_in_contrainte_egal677); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal681); 

            toString="condEgal.push_back(new ConditionEgal("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));";

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "contrainte_egal"



    // $ANTLR start "contrainte_adj"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:117:2: contrainte_adj returns [String toString] : ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' ;
    public final String contrainte_adj() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:117:43: ( ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:117:45: ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')'
            {
            match(input,ADJ,FOLLOW_ADJ_in_contrainte_adj695); 

            match(input,16,FOLLOW_16_in_contrainte_adj697); 

            match(input,15,FOLLOW_15_in_contrainte_adj699); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj703); 

            match(input,20,FOLLOW_20_in_contrainte_adj705); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj709); 

            match(input,18,FOLLOW_18_in_contrainte_adj711); 

            match(input,15,FOLLOW_15_in_contrainte_adj713); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj717); 

            match(input,20,FOLLOW_20_in_contrainte_adj719); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj723); 

            match(input,17,FOLLOW_17_in_contrainte_adj725); 

            toString="condAdj.push_back(new ConditionAdj("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));";

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "contrainte_adj"



    // $ANTLR start "contrainte_adj_ext"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:118:2: contrainte_adj_ext returns [String toString] : ADJEXT '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' ;
    public final String contrainte_adj_ext() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:118:47: ( ADJEXT '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:118:49: ADJEXT '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')'
            {
            match(input,ADJEXT,FOLLOW_ADJEXT_in_contrainte_adj_ext739); 

            match(input,16,FOLLOW_16_in_contrainte_adj_ext741); 

            match(input,15,FOLLOW_15_in_contrainte_adj_ext743); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj_ext747); 

            match(input,20,FOLLOW_20_in_contrainte_adj_ext749); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj_ext753); 

            match(input,18,FOLLOW_18_in_contrainte_adj_ext755); 

            match(input,15,FOLLOW_15_in_contrainte_adj_ext757); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj_ext761); 

            match(input,20,FOLLOW_20_in_contrainte_adj_ext763); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj_ext767); 

            match(input,17,FOLLOW_17_in_contrainte_adj_ext769); 

            toString="condAdj_ext.push_back(new ConditionAdj_Ext("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));";

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "contrainte_adj_ext"



    // $ANTLR start "contrainte_adj_int"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:119:2: contrainte_adj_int returns [String toString] : ADJINT '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' ;
    public final String contrainte_adj_int() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:119:47: ( ADJINT '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:119:49: ADJINT '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')'
            {
            match(input,ADJINT,FOLLOW_ADJINT_in_contrainte_adj_int783); 

            match(input,16,FOLLOW_16_in_contrainte_adj_int785); 

            match(input,15,FOLLOW_15_in_contrainte_adj_int787); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj_int791); 

            match(input,20,FOLLOW_20_in_contrainte_adj_int793); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj_int797); 

            match(input,18,FOLLOW_18_in_contrainte_adj_int799); 

            match(input,15,FOLLOW_15_in_contrainte_adj_int801); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj_int805); 

            match(input,20,FOLLOW_20_in_contrainte_adj_int807); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj_int811); 

            match(input,17,FOLLOW_17_in_contrainte_adj_int813); 

            toString="condAdj_int.push_back(new ConditionAdj_Int("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));";

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "contrainte_adj_int"



    // $ANTLR start "condition_unique"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:121:2: condition_unique returns [String toString] : '$' i= INT '.' att_i= ID op= OP_COMP (val= INT |val= BOOL |val= FLOAT ) ;
    public final String condition_unique() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token op=null;
        Token val=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:121:46: ( '$' i= INT '.' att_i= ID op= OP_COMP (val= INT |val= BOOL |val= FLOAT ) )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:121:48: '$' i= INT '.' att_i= ID op= OP_COMP (val= INT |val= BOOL |val= FLOAT )
            {
            System.out.println("class ConditionUnique"+n+"_"+(++n3)+" : public ConditionUnique{");
            	System.out.println("bool estVerifiee(Noeud* n){return ");

            match(input,15,FOLLOW_15_in_condition_unique833); 

            i=(Token)match(input,INT,FOLLOW_INT_in_condition_unique837); 

            match(input,20,FOLLOW_20_in_condition_unique839); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_condition_unique843); 

            op=(Token)match(input,OP_COMP,FOLLOW_OP_COMP_in_condition_unique847); 

            System.out.print("(n->getAttribut(\""+(att_i!=null?att_i.getText():null)+"\")->");

            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:124:2: (val= INT |val= BOOL |val= FLOAT )
            int alt24=3;
            switch ( input.LA(1) ) {
            case INT:
                {
                alt24=1;
                }
                break;
            case BOOL:
                {
                alt24=2;
                }
                break;
            case FLOAT:
                {
                alt24=3;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 24, 0, input);

                throw nvae;

            }

            switch (alt24) {
                case 1 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:124:3: val= INT
                    {
                    val=(Token)match(input,INT,FOLLOW_INT_in_condition_unique855); 

                    System.out.print("intValue()"+(op!=null?op.getText():null)+(val!=null?val.getText():null));

                    }
                    break;
                case 2 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:124:66: val= BOOL
                    {
                    val=(Token)match(input,BOOL,FOLLOW_BOOL_in_condition_unique863); 

                    System.out.print("boolValue()"+(op!=null?op.getText():null)+(val!=null?val.getText():null));

                    }
                    break;
                case 3 :
                    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:124:131: val= FLOAT
                    {
                    val=(Token)match(input,FLOAT,FOLLOW_FLOAT_in_condition_unique871); 

                    System.out.print("floatValue()"+(op!=null?op.getText():null)+(val!=null?val.getText():null));

                    }
                    break;

            }


            System.out.println(");}};");
            		System.out.println("ConditionUnique"+n+"_"+n3+"* c"+n+"_"+n3+" = new ConditionUnique"+n+"_"+n3+"(); c"+n+"_"+n3+"->indice = "+(i!=null?i.getText():null)+";");
            	toString = "condUnique.push_back(c"+n+"_"+n3+");";

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "condition_unique"



    // $ANTLR start "contrainte_generale"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:129:2: contrainte_generale returns [String toString] : '@' i= ID ;
    public final String contrainte_generale() throws RecognitionException {
        String toString = null;


        Token i=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:129:47: ( '@' i= ID )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:129:48: '@' i= ID
            {
            match(input,23,FOLLOW_23_in_contrainte_generale890); 

            i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_generale894); 

            toString="condGen.push_back(new "+(i!=null?i.getText():null)+"());";

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return toString;
    }
    // $ANTLR end "contrainte_generale"



    // $ANTLR start "expr_calcul"
    // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:131:2: expr_calcul : att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final void expr_calcul() throws RecognitionException {
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:131:14: (att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\user\\Documents\\School\\Ponts\\stage\\source\\Imagine\\compil\\batiment.g:131:16: att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            att_i=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul907); 

            match(input,22,FOLLOW_22_in_expr_calcul909); 

            match(input,15,FOLLOW_15_in_expr_calcul911); 

            j=(Token)match(input,INT,FOLLOW_INT_in_expr_calcul915); 

            match(input,20,FOLLOW_20_in_expr_calcul917); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul921); 

            System.out.println("nouveau->setAttribut(\""+(att_i!=null?att_i.getText():null)+"\",nouveau->getEnfants()["+(j!=null?j.getText():null)+"]->getAttribut(\""+(att_j!=null?att_j.getText():null)+"\"));");

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return ;
    }
    // $ANTLR end "expr_calcul"

    // Delegated rules


 

    public static final BitSet FOLLOW_dinclude_in_grammaire28 = new BitSet(new long[]{0x0000000010000000L});
    public static final BitSet FOLLOW_def_nom_in_grammaire32 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_def_regles_in_grammaire37 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_14_in_dinclude49 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_dinclude53 = new BitSet(new long[]{0x0000000000004002L});
    public static final BitSet FOLLOW_28_in_def_nom69 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_def_nom73 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_regle_in_def_regles84 = new BitSet(new long[]{0x0000000000000402L});
    public static final BitSet FOLLOW_ID_in_regle96 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_regle98 = new BitSet(new long[]{0x000000006E000400L});
    public static final BitSet FOLLOW_membre_droit_in_regle107 = new BitSet(new long[]{0x0000000080040000L});
    public static final BitSet FOLLOW_18_in_regle110 = new BitSet(new long[]{0x000000006E000400L});
    public static final BitSet FOLLOW_membre_droit_in_regle112 = new BitSet(new long[]{0x0000000080040000L});
    public static final BitSet FOLLOW_31_in_regle122 = new BitSet(new long[]{0x0000000100818070L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle129 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_regle134 = new BitSet(new long[]{0x0000000080000002L});
    public static final BitSet FOLLOW_31_in_regle139 = new BitSet(new long[]{0x0000000000800400L});
    public static final BitSet FOLLOW_liste_calcul_in_regle142 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_23_in_regle150 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_regle154 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_regle159 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_membreStandard_in_membre_droit178 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_operateur_in_membre_droit182 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_membreStandard198 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_30_in_operateur214 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_26_in_operateur222 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_25_in_operateur229 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_27_in_operateur236 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_29_in_operateur244 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_operateur251 = new BitSet(new long[]{0x000000006E000400L});
    public static final BitSet FOLLOW_ID_in_operateur261 = new BitSet(new long[]{0x0000000080040000L});
    public static final BitSet FOLLOW_31_in_operateur266 = new BitSet(new long[]{0x0000000100000010L});
    public static final BitSet FOLLOW_contrainte_op_membres_in_operateur268 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_operateur270 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_operateur_imbrique_in_operateur277 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_operateur284 = new BitSet(new long[]{0x0000000080000000L});
    public static final BitSet FOLLOW_31_in_operateur286 = new BitSet(new long[]{0x0000000100818070L});
    public static final BitSet FOLLOW_liste_contraintes_in_operateur293 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_operateur298 = new BitSet(new long[]{0x0000000000060000L});
    public static final BitSet FOLLOW_18_in_operateur304 = new BitSet(new long[]{0x0000000080800000L});
    public static final BitSet FOLLOW_31_in_operateur307 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_liste_calcul_in_operateur309 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_23_in_operateur316 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_operateur320 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_operateur325 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_operateur330 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_30_in_operateur_imbrique348 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_26_in_operateur_imbrique356 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_25_in_operateur_imbrique363 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_27_in_operateur_imbrique370 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_29_in_operateur_imbrique378 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_operateur_imbrique385 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_operateur_imbrique391 = new BitSet(new long[]{0x0000000080040000L});
    public static final BitSet FOLLOW_31_in_operateur_imbrique396 = new BitSet(new long[]{0x0000000100000010L});
    public static final BitSet FOLLOW_contrainte_op_membres_imbrique_in_operateur_imbrique398 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_operateur_imbrique400 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_operateur_imbrique406 = new BitSet(new long[]{0x0000000080000000L});
    public static final BitSet FOLLOW_31_in_operateur_imbrique408 = new BitSet(new long[]{0x0000000100818070L});
    public static final BitSet FOLLOW_liste_contraintes_in_operateur_imbrique415 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_operateur_imbrique420 = new BitSet(new long[]{0x0000000000060000L});
    public static final BitSet FOLLOW_18_in_operateur_imbrique426 = new BitSet(new long[]{0x0000000080800000L});
    public static final BitSet FOLLOW_31_in_operateur_imbrique429 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_liste_calcul_in_operateur_imbrique431 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_23_in_operateur_imbrique438 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_operateur_imbrique442 = new BitSet(new long[]{0x0000000100000000L});
    public static final BitSet FOLLOW_32_in_operateur_imbrique447 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_operateur_imbrique452 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_op_membres463 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_contrainte_op_membres465 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_op_membres469 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_contrainte_op_membres471 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte_op_membres473 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_op_membres477 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_op_membres479 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_op_membres483 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_op_membres485 = new BitSet(new long[]{0x0000000000000012L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_op_membres_imbrique501 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_contrainte_op_membres_imbrique503 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_op_membres_imbrique507 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_contrainte_op_membres_imbrique509 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte_op_membres_imbrique511 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_op_membres_imbrique515 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_op_membres_imbrique517 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_op_membres_imbrique521 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_op_membres_imbrique523 = new BitSet(new long[]{0x0000000000000012L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes544 = new BitSet(new long[]{0x0000000001000002L});
    public static final BitSet FOLLOW_24_in_liste_contraintes548 = new BitSet(new long[]{0x0000000000818070L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes552 = new BitSet(new long[]{0x0000000001000002L});
    public static final BitSet FOLLOW_expr_calcul_in_liste_calcul571 = new BitSet(new long[]{0x0000000000200000L});
    public static final BitSet FOLLOW_21_in_liste_calcul573 = new BitSet(new long[]{0x0000000000000402L});
    public static final BitSet FOLLOW_contrainte_egal_in_contrainte593 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_adj_in_contrainte601 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_adj_ext_in_contrainte609 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_adj_int_in_contrainte616 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_condition_unique_in_contrainte623 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_generale_in_contrainte631 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_16_in_contrainte637 = new BitSet(new long[]{0x0000000000818070L});
    public static final BitSet FOLLOW_contrainte_in_contrainte641 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte644 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_15_in_contrainte_egal657 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal661 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_egal663 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal667 = new BitSet(new long[]{0x0000000000400000L});
    public static final BitSet FOLLOW_22_in_contrainte_egal669 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_egal671 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal675 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_egal677 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal681 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_adj695 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_contrainte_adj697 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj699 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj703 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_adj705 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj709 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_contrainte_adj711 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj713 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj717 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_adj719 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj723 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj725 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJEXT_in_contrainte_adj_ext739 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_contrainte_adj_ext741 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj_ext743 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj_ext747 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_adj_ext749 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj_ext753 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_contrainte_adj_ext755 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj_ext757 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj_ext761 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_adj_ext763 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj_ext767 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj_ext769 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJINT_in_contrainte_adj_int783 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_contrainte_adj_int785 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj_int787 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj_int791 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_adj_int793 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj_int797 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_contrainte_adj_int799 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj_int801 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj_int805 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_contrainte_adj_int807 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj_int811 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj_int813 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_15_in_condition_unique833 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_condition_unique837 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_condition_unique839 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_condition_unique843 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_OP_COMP_in_condition_unique847 = new BitSet(new long[]{0x0000000000000A80L});
    public static final BitSet FOLLOW_INT_in_condition_unique855 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_BOOL_in_condition_unique863 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_FLOAT_in_condition_unique871 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_23_in_contrainte_generale890 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_contrainte_generale894 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_expr_calcul907 = new BitSet(new long[]{0x0000000000400000L});
    public static final BitSet FOLLOW_22_in_expr_calcul909 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_expr_calcul911 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_INT_in_expr_calcul915 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_expr_calcul917 = new BitSet(new long[]{0x0000000000000400L});
    public static final BitSet FOLLOW_ID_in_expr_calcul921 = new BitSet(new long[]{0x0000000000000002L});

}