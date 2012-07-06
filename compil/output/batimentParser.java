// $ANTLR 3.4 C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g 2012-07-04 17:02:28

import java.util.LinkedList;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class batimentParser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "ADJ", "EXPONENT", "FLOAT", "ID", "INT", "OP_COMP", "WS", "'#'", "'$'", "'('", "')'", "','", "'->'", "'.'", "';'", "'='", "'@'", "'^'", "'cluster'", "'cycle'", "'ensemble'", "'false'", "'grammaire'", "'sequence'", "'true'", "'{'", "'}'"
    };

    public static final int EOF=-1;
    public static final int T__11=11;
    public static final int T__12=12;
    public static final int T__13=13;
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
    public static final int ADJ=4;
    public static final int EXPONENT=5;
    public static final int FLOAT=6;
    public static final int ID=7;
    public static final int INT=8;
    public static final int OP_COMP=9;
    public static final int WS=10;

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
    public String getGrammarFileName() { return "C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g"; }


    int n=0;
    int n2=0;


    // $ANTLR start "grammaire"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:12:1: grammaire : dinclude dnom= def_nom def_regles ;
    public final void grammaire() throws RecognitionException {
        String dnom =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:13:2: ( dinclude dnom= def_nom def_regles )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:13:4: dinclude dnom= def_nom def_regles
            {
            System.out.println("#include \"../grammaire/Parser.h\"");
            System.out.println("#include <vector>");
            System.out.println("#include <string>");
            System.out.println("#include \"../grammaire/Regle.h\"");
            System.out.println("#include \"../grammaire/OperateurCycle.h\"");
            System.out.println("#include \"../grammaire/MembreStandard.h\"");
            System.out.println("#include \"../grammaire/OperateurSequence.h\"");
            System.out.println("#include \"../grammaire/OperateurCluster.h\"");
            System.out.println("#include \"../grammaire/OperateurEnsemble.h\"");
            System.out.println("#include \"../grammaire/condition/ConditionAdj.h\"");
            System.out.println("#include \"../grammaire/condition/ConditionEgal.h\"");
            System.out.println("#include \"../grammaire/regles/CalculAttributs.h\"");

            pushFollow(FOLLOW_dinclude_in_grammaire27);
            dinclude();

            state._fsp--;


            pushFollow(FOLLOW_def_nom_in_grammaire31);
            dnom=def_nom();

            state._fsp--;


            System.out.println("class Parser"+dnom+" : public Parser {");
            System.out.println("public:");
            	System.out.println("Parser"+dnom+"(){");

            pushFollow(FOLLOW_def_regles_in_grammaire36);
            def_regles();

            state._fsp--;



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
    // $ANTLR end "grammaire"



    // $ANTLR start "dinclude"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:33:1: dinclude : ( '#' i= ID )* ;
    public final void dinclude() throws RecognitionException {
        Token i=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:2: ( ( '#' i= ID )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:4: ( '#' i= ID )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:4: ( '#' i= ID )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( (LA1_0==11) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:5: '#' i= ID
            	    {
            	    match(input,11,FOLLOW_11_in_dinclude48); 

            	    i=(Token)match(input,ID,FOLLOW_ID_in_dinclude52); 

            	    System.out.println("#include \""+(i!=null?i.getText():null)+".cpp\"");

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:1: def_nom returns [String nom] : 'grammaire' id= ID ;
    public final String def_nom() throws RecognitionException {
        String nom = null;


        Token id=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:29: ( 'grammaire' id= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:31: 'grammaire' id= ID
            {
            match(input,26,FOLLOW_26_in_def_nom68); 

            id=(Token)match(input,ID,FOLLOW_ID_in_def_nom72); 

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:37:1: def_regles : ( regle )* ;
    public final void def_regles() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:2: ( ( regle )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:4: ( regle )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:4: ( regle )*
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==ID) ) {
                    alt2=1;
                }


                switch (alt2) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:38:4: regle
            	    {
            	    pushFollow(FOLLOW_regle_in_def_regles83);
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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:40:1: regle : i1= ID '->' membre_droit ( ',' membre_droit )* '{' (lc= liste_contraintes )? '}' ( '{' ( liste_calcul | '@' c= ID ) '}' )? ;
    public final void regle() throws RecognitionException {
        Token i1=null;
        Token c=null;
        List<String> lc =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:40:7: (i1= ID '->' membre_droit ( ',' membre_droit )* '{' (lc= liste_contraintes )? '}' ( '{' ( liste_calcul | '@' c= ID ) '}' )? )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:40:9: i1= ID '->' membre_droit ( ',' membre_droit )* '{' (lc= liste_contraintes )? '}' ( '{' ( liste_calcul | '@' c= ID ) '}' )?
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle95); 

            match(input,16,FOLLOW_16_in_regle97); 

            System.out.println("vector<MembreDroit*> v"+n+";");

            pushFollow(FOLLOW_membre_droit_in_regle106);
            membre_droit();

            state._fsp--;


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:16: ( ',' membre_droit )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==15) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:17: ',' membre_droit
            	    {
            	    match(input,15,FOLLOW_15_in_regle109); 

            	    pushFollow(FOLLOW_membre_droit_in_regle111);
            	    membre_droit();

            	    state._fsp--;


            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            System.out.println("Regle* r"+n+" = new Regle(\""+(i1!=null?i1.getText():null)+"\",v"+n+");");System.out.println("ajouterRegle(r"+n+");");

            match(input,29,FOLLOW_29_in_regle121); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:7: (lc= liste_contraintes )?
            int alt4=2;
            int LA4_0 = input.LA(1);

            if ( (LA4_0==ADJ||(LA4_0 >= 12 && LA4_0 <= 13)||LA4_0==20) ) {
                alt4=1;
            }
            switch (alt4) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:8: lc= liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle128);
                    lc=liste_contraintes();

                    state._fsp--;


                    for(String s:lc) System.out.println("r"+n+"->"+s);

                    }
                    break;

            }


            match(input,30,FOLLOW_30_in_regle133); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:3: ( '{' ( liste_calcul | '@' c= ID ) '}' )?
            int alt6=2;
            int LA6_0 = input.LA(1);

            if ( (LA6_0==29) ) {
                alt6=1;
            }
            switch (alt6) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:4: '{' ( liste_calcul | '@' c= ID ) '}'
                    {
                    match(input,29,FOLLOW_29_in_regle138); 

                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:8: ( liste_calcul | '@' c= ID )
                    int alt5=2;
                    int LA5_0 = input.LA(1);

                    if ( (LA5_0==ID) ) {
                        alt5=1;
                    }
                    else if ( (LA5_0==20) ) {
                        alt5=2;
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 5, 0, input);

                        throw nvae;

                    }
                    switch (alt5) {
                        case 1 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:9: liste_calcul
                            {
                            pushFollow(FOLLOW_liste_calcul_in_regle141);
                            liste_calcul();

                            state._fsp--;


                            System.out.println("r"+n+"->calculAtt = new Calcul"+n2+"();");

                            }
                            break;
                        case 2 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:46:5: '@' c= ID
                            {
                            match(input,20,FOLLOW_20_in_regle149); 

                            c=(Token)match(input,ID,FOLLOW_ID_in_regle153); 

                            System.out.println("r"+n+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                            }
                            break;

                    }


                    match(input,30,FOLLOW_30_in_regle158); 

                    }
                    break;

            }


            n++;n2++;

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:1: membre_droit : ( membreStandard | operateur );
    public final void membre_droit() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:49:2: ( membreStandard | operateur )
            int alt7=2;
            int LA7_0 = input.LA(1);

            if ( (LA7_0==ID) ) {
                alt7=1;
            }
            else if ( ((LA7_0 >= 22 && LA7_0 <= 24)||LA7_0==27) ) {
                alt7=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 7, 0, input);

                throw nvae;

            }
            switch (alt7) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:49:5: membreStandard
                    {
                    pushFollow(FOLLOW_membreStandard_in_membre_droit177);
                    membreStandard();

                    state._fsp--;


                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:49:22: operateur
                    {
                    pushFollow(FOLLOW_operateur_in_membre_droit181);
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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:52:1: membreStandard : i2= ID ;
    public final void membreStandard() throws RecognitionException {
        Token i2=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:53:2: (i2= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:53:5: i2= ID
            {
            i2=(Token)match(input,ID,FOLLOW_ID_in_membreStandard197); 

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:55:1: operateur : ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' ) '(' i2= ID ( '{' contrainte_op_membres '}' )? ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')' ;
    public final void operateur() throws RecognitionException {
        Token i2=null;
        Token c=null;
        List<String> lc =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:2: ( ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' ) '(' i2= ID ( '{' contrainte_op_membres '}' )? ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:4: ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' ) '(' i2= ID ( '{' contrainte_op_membres '}' )? ',' '{' (lc= liste_contraintes )? '}' ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )? ')'
            {
            String opType="";

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:23: ( 'sequence' | 'cycle' | 'cluster' | 'ensemble' )
            int alt8=4;
            switch ( input.LA(1) ) {
            case 27:
                {
                alt8=1;
                }
                break;
            case 23:
                {
                alt8=2;
                }
                break;
            case 22:
                {
                alt8=3;
                }
                break;
            case 24:
                {
                alt8=4;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 8, 0, input);

                throw nvae;

            }

            switch (alt8) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:56:24: 'sequence'
                    {
                    match(input,27,FOLLOW_27_in_operateur213); 

                    opType="OperateurSequence";

                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:57:5: 'cycle'
                    {
                    match(input,23,FOLLOW_23_in_operateur221); 

                    opType="OperateurCycle";

                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:58:4: 'cluster'
                    {
                    match(input,22,FOLLOW_22_in_operateur228); 

                    opType="OperateurCluster";

                    }
                    break;
                case 4 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:59:4: 'ensemble'
                    {
                    match(input,24,FOLLOW_24_in_operateur235); 

                    opType="OperateurEnsemble";

                    }
                    break;

            }


            match(input,13,FOLLOW_13_in_operateur242); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_operateur248); 

            System.out.println(opType+"* op"+n2+"= new "+opType+"(\""+(i2!=null?i2.getText():null)+"\",\"OPE\");");

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:101: ( '{' contrainte_op_membres '}' )?
            int alt9=2;
            int LA9_0 = input.LA(1);

            if ( (LA9_0==29) ) {
                alt9=1;
            }
            switch (alt9) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:102: '{' contrainte_op_membres '}'
                    {
                    match(input,29,FOLLOW_29_in_operateur253); 

                    pushFollow(FOLLOW_contrainte_op_membres_in_operateur255);
                    contrainte_op_membres();

                    state._fsp--;


                    match(input,30,FOLLOW_30_in_operateur257); 

                    }
                    break;

            }


            match(input,15,FOLLOW_15_in_operateur263); 

            match(input,29,FOLLOW_29_in_operateur265); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:61:11: (lc= liste_contraintes )?
            int alt10=2;
            int LA10_0 = input.LA(1);

            if ( (LA10_0==ADJ||(LA10_0 >= 12 && LA10_0 <= 13)||LA10_0==20) ) {
                alt10=1;
            }
            switch (alt10) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:61:12: lc= liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_operateur272);
                    lc=liste_contraintes();

                    state._fsp--;


                    for(String s:lc) System.out.println("op"+n2+"->"+s);

                    }
                    break;

            }


            match(input,30,FOLLOW_30_in_operateur277); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:62:4: ( ',' ( '{' liste_calcul | '@' c= ID ) '}' )?
            int alt12=2;
            int LA12_0 = input.LA(1);

            if ( (LA12_0==15) ) {
                alt12=1;
            }
            switch (alt12) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:62:5: ',' ( '{' liste_calcul | '@' c= ID ) '}'
                    {
                    match(input,15,FOLLOW_15_in_operateur283); 

                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:62:9: ( '{' liste_calcul | '@' c= ID )
                    int alt11=2;
                    int LA11_0 = input.LA(1);

                    if ( (LA11_0==29) ) {
                        alt11=1;
                    }
                    else if ( (LA11_0==20) ) {
                        alt11=2;
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 11, 0, input);

                        throw nvae;

                    }
                    switch (alt11) {
                        case 1 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:62:10: '{' liste_calcul
                            {
                            match(input,29,FOLLOW_29_in_operateur286); 

                            pushFollow(FOLLOW_liste_calcul_in_operateur288);
                            liste_calcul();

                            state._fsp--;


                            System.out.println("op"+n2+"->calculAtt = new Calcul"+n2+"();");

                            }
                            break;
                        case 2 :
                            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:63:4: '@' c= ID
                            {
                            match(input,20,FOLLOW_20_in_operateur295); 

                            c=(Token)match(input,ID,FOLLOW_ID_in_operateur299); 

                            System.out.println("op"+n2+"->calculAtt = new "+(c!=null?c.getText():null)+"();");

                            }
                            break;

                    }


                    match(input,30,FOLLOW_30_in_operateur304); 

                    }
                    break;

            }


            match(input,14,FOLLOW_14_in_operateur309); 

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



    // $ANTLR start "contrainte_op_membres"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:65:1: contrainte_op_membres : ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )* ;
    public final void contrainte_op_membres() throws RecognitionException {
        Token att=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:66:2: ( ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:66:4: ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:66:4: ( ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')' )*
            loop13:
            do {
                int alt13=2;
                int LA13_0 = input.LA(1);

                if ( (LA13_0==ADJ) ) {
                    alt13=1;
                }


                switch (alt13) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:66:5: ADJ '(' att= ID ',' '#' j= INT '.' att_j= ID ')'
            	    {
            	    match(input,ADJ,FOLLOW_ADJ_in_contrainte_op_membres322); 

            	    match(input,13,FOLLOW_13_in_contrainte_op_membres324); 

            	    att=(Token)match(input,ID,FOLLOW_ID_in_contrainte_op_membres328); 

            	    match(input,15,FOLLOW_15_in_contrainte_op_membres330); 

            	    match(input,11,FOLLOW_11_in_contrainte_op_membres332); 

            	    j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_op_membres336); 

            	    match(input,17,FOLLOW_17_in_contrainte_op_membres338); 

            	    att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_op_membres342); 

            	    match(input,14,FOLLOW_14_in_contrainte_op_membres344); 

            	    System.out.println("op"+n2+"->condAdjExt.push_back(new ConditionAdj(0,\""+(att!=null?att.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

            	    }
            	    break;

            	default :
            	    break loop13;
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



    // $ANTLR start "liste_contraintes"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:68:1: liste_contraintes returns [List<String> liste] :c= contrainte ( '^' c2= contrainte )* ;
    public final List<String> liste_contraintes() throws RecognitionException {
        List<String> liste = null;


        String c =null;

        String c2 =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:68:47: (c= contrainte ( '^' c2= contrainte )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:69:2: c= contrainte ( '^' c2= contrainte )*
            {
            liste = new LinkedList<String>();

            pushFollow(FOLLOW_contrainte_in_liste_contraintes365);
            c=contrainte();

            state._fsp--;


            liste.add(c);

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:69:76: ( '^' c2= contrainte )*
            loop14:
            do {
                int alt14=2;
                int LA14_0 = input.LA(1);

                if ( (LA14_0==21) ) {
                    alt14=1;
                }


                switch (alt14) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:69:77: '^' c2= contrainte
            	    {
            	    match(input,21,FOLLOW_21_in_liste_contraintes369); 

            	    pushFollow(FOLLOW_contrainte_in_liste_contraintes373);
            	    c2=contrainte();

            	    state._fsp--;


            	    liste.add(c2);

            	    }
            	    break;

            	default :
            	    break loop14;
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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:71:1: liste_calcul : ( expr_calcul ';' )+ ;
    public final void liste_calcul() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:72:2: ( ( expr_calcul ';' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:73:2: ( expr_calcul ';' )+
            {
             System.out.println("class Calcul"+n2+" : public CalculAttributs {");System.out.println("void calculAttrib(Noeud* nouveau){");

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:74:2: ( expr_calcul ';' )+
            int cnt15=0;
            loop15:
            do {
                int alt15=2;
                int LA15_0 = input.LA(1);

                if ( (LA15_0==ID) ) {
                    alt15=1;
                }


                switch (alt15) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:74:3: expr_calcul ';'
            	    {
            	    pushFollow(FOLLOW_expr_calcul_in_liste_calcul392);
            	    expr_calcul();

            	    state._fsp--;


            	    match(input,18,FOLLOW_18_in_liste_calcul394); 

            	    }
            	    break;

            	default :
            	    if ( cnt15 >= 1 ) break loop15;
                        EarlyExitException eee =
                            new EarlyExitException(15, input);
                        throw eee;
                }
                cnt15++;
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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:76:2: contrainte returns [String toString] : (c= contrainte_egal |c= contrainte_adj |c= condition_unique |c= contrainte_generale | '(' c= contrainte ')' );
    public final String contrainte() throws RecognitionException {
        String toString = null;


        String c =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:76:38: (c= contrainte_egal |c= contrainte_adj |c= condition_unique |c= contrainte_generale | '(' c= contrainte ')' )
            int alt16=5;
            switch ( input.LA(1) ) {
            case 12:
                {
                int LA16_1 = input.LA(2);

                if ( (LA16_1==INT) ) {
                    int LA16_5 = input.LA(3);

                    if ( (LA16_5==17) ) {
                        int LA16_6 = input.LA(4);

                        if ( (LA16_6==ID) ) {
                            int LA16_7 = input.LA(5);

                            if ( (LA16_7==19) ) {
                                alt16=1;
                            }
                            else if ( (LA16_7==OP_COMP) ) {
                                alt16=3;
                            }
                            else {
                                NoViableAltException nvae =
                                    new NoViableAltException("", 16, 7, input);

                                throw nvae;

                            }
                        }
                        else {
                            NoViableAltException nvae =
                                new NoViableAltException("", 16, 6, input);

                            throw nvae;

                        }
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 16, 5, input);

                        throw nvae;

                    }
                }
                else {
                    NoViableAltException nvae =
                        new NoViableAltException("", 16, 1, input);

                    throw nvae;

                }
                }
                break;
            case ADJ:
                {
                alt16=2;
                }
                break;
            case 20:
                {
                alt16=4;
                }
                break;
            case 13:
                {
                alt16=5;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 16, 0, input);

                throw nvae;

            }

            switch (alt16) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:77:2: c= contrainte_egal
                    {
                    pushFollow(FOLLOW_contrainte_egal_in_contrainte414);
                    c=contrainte_egal();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:78:2: c= contrainte_adj
                    {
                    pushFollow(FOLLOW_contrainte_adj_in_contrainte422);
                    c=contrainte_adj();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:79:2: c= condition_unique
                    {
                    pushFollow(FOLLOW_condition_unique_in_contrainte430);
                    c=condition_unique();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 4 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:80:2: c= contrainte_generale
                    {
                    pushFollow(FOLLOW_contrainte_generale_in_contrainte438);
                    c=contrainte_generale();

                    state._fsp--;


                    toString = c;

                    }
                    break;
                case 5 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:81:2: '(' c= contrainte ')'
                    {
                    match(input,13,FOLLOW_13_in_contrainte444); 

                    pushFollow(FOLLOW_contrainte_in_contrainte448);
                    c=contrainte();

                    state._fsp--;


                    toString = c;

                    match(input,14,FOLLOW_14_in_contrainte451); 

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:83:2: contrainte_egal returns [String toString] : '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final String contrainte_egal() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:83:43: ( '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:83:45: '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            match(input,12,FOLLOW_12_in_contrainte_egal464); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal468); 

            match(input,17,FOLLOW_17_in_contrainte_egal470); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal474); 

            match(input,19,FOLLOW_19_in_contrainte_egal476); 

            match(input,12,FOLLOW_12_in_contrainte_egal478); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal482); 

            match(input,17,FOLLOW_17_in_contrainte_egal484); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal488); 

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:84:2: contrainte_adj returns [String toString] : ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' ;
    public final String contrainte_adj() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:84:43: ( ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:84:45: ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')'
            {
            match(input,ADJ,FOLLOW_ADJ_in_contrainte_adj502); 

            match(input,13,FOLLOW_13_in_contrainte_adj504); 

            match(input,12,FOLLOW_12_in_contrainte_adj506); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj510); 

            match(input,17,FOLLOW_17_in_contrainte_adj512); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj516); 

            match(input,15,FOLLOW_15_in_contrainte_adj518); 

            match(input,12,FOLLOW_12_in_contrainte_adj520); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj524); 

            match(input,17,FOLLOW_17_in_contrainte_adj526); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj530); 

            match(input,14,FOLLOW_14_in_contrainte_adj532); 

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



    // $ANTLR start "condition_unique"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:86:2: condition_unique returns [String toString] : '$' i= INT '.' att_i= ID op= OP_COMP val= constante ;
    public final String condition_unique() throws RecognitionException {
        String toString = null;


        Token i=null;
        Token att_i=null;
        Token op=null;
        batimentParser.constante_return val =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:86:46: ( '$' i= INT '.' att_i= ID op= OP_COMP val= constante )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:86:48: '$' i= INT '.' att_i= ID op= OP_COMP val= constante
            {
            System.out.println("class ConditionUnique"+n+"_"+(++n2)+" : public ConditionUnique{");
            	System.out.println("bool estVerifiee(Noeud* n){return ");

            match(input,12,FOLLOW_12_in_condition_unique552); 

            i=(Token)match(input,INT,FOLLOW_INT_in_condition_unique556); 

            match(input,17,FOLLOW_17_in_condition_unique558); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_condition_unique562); 

            op=(Token)match(input,OP_COMP,FOLLOW_OP_COMP_in_condition_unique566); 

            pushFollow(FOLLOW_constante_in_condition_unique570);
            val=constante();

            state._fsp--;


            System.out.print("((int) n->getAttribut(\""+(att_i!=null?att_i.getText():null)+"\"))"+(op!=null?op.getText():null)+(val!=null?input.toString(val.start,val.stop):null));
            		System.out.println(";}};");
            		System.out.println("ConditionUnique"+n+"_"+n2+"* c"+n+"_"+n2+" = new ConditionUnique"+n+"_"+n2+"(); c"+n+"_"+n2+"->indice = "+(i!=null?i.getText():null)+";");
            	toString = "condUnique.push_back(c"+n+"_"+n2+");";

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:94:2: contrainte_generale returns [String toString] : '@' i= ID ;
    public final String contrainte_generale() throws RecognitionException {
        String toString = null;


        Token i=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:94:47: ( '@' i= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:94:48: '@' i= ID
            {
            match(input,20,FOLLOW_20_in_contrainte_generale586); 

            i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_generale590); 

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:96:2: expr_calcul : att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final void expr_calcul() throws RecognitionException {
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:96:14: (att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:96:16: att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            att_i=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul603); 

            match(input,19,FOLLOW_19_in_expr_calcul605); 

            match(input,12,FOLLOW_12_in_expr_calcul607); 

            j=(Token)match(input,INT,FOLLOW_INT_in_expr_calcul611); 

            match(input,17,FOLLOW_17_in_expr_calcul613); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul617); 

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


    public static class constante_return extends ParserRuleReturnScope {
    };


    // $ANTLR start "constante"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:99:1: constante : ( 'true' | 'false' | INT );
    public final batimentParser.constante_return constante() throws RecognitionException {
        batimentParser.constante_return retval = new batimentParser.constante_return();
        retval.start = input.LT(1);


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:99:11: ( 'true' | 'false' | INT )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:
            {
            if ( input.LA(1)==INT||input.LA(1)==25||input.LA(1)==28 ) {
                input.consume();
                state.errorRecovery=false;
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                throw mse;
            }


            }

            retval.stop = input.LT(-1);


        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return retval;
    }
    // $ANTLR end "constante"

    // Delegated rules


 

    public static final BitSet FOLLOW_dinclude_in_grammaire27 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_def_nom_in_grammaire31 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_def_regles_in_grammaire36 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_11_in_dinclude48 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_dinclude52 = new BitSet(new long[]{0x0000000000000802L});
    public static final BitSet FOLLOW_26_in_def_nom68 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_def_nom72 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_regle_in_def_regles83 = new BitSet(new long[]{0x0000000000000082L});
    public static final BitSet FOLLOW_ID_in_regle95 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle97 = new BitSet(new long[]{0x0000000009C00080L});
    public static final BitSet FOLLOW_membre_droit_in_regle106 = new BitSet(new long[]{0x0000000020008000L});
    public static final BitSet FOLLOW_15_in_regle109 = new BitSet(new long[]{0x0000000009C00080L});
    public static final BitSet FOLLOW_membre_droit_in_regle111 = new BitSet(new long[]{0x0000000020008000L});
    public static final BitSet FOLLOW_29_in_regle121 = new BitSet(new long[]{0x0000000040103010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle128 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_30_in_regle133 = new BitSet(new long[]{0x0000000020000002L});
    public static final BitSet FOLLOW_29_in_regle138 = new BitSet(new long[]{0x0000000000100080L});
    public static final BitSet FOLLOW_liste_calcul_in_regle141 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_20_in_regle149 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_regle153 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_30_in_regle158 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_membreStandard_in_membre_droit177 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_operateur_in_membre_droit181 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_membreStandard197 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_27_in_operateur213 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_23_in_operateur221 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_22_in_operateur228 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_24_in_operateur235 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_13_in_operateur242 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_operateur248 = new BitSet(new long[]{0x0000000020008000L});
    public static final BitSet FOLLOW_29_in_operateur253 = new BitSet(new long[]{0x0000000040000010L});
    public static final BitSet FOLLOW_contrainte_op_membres_in_operateur255 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_30_in_operateur257 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_operateur263 = new BitSet(new long[]{0x0000000020000000L});
    public static final BitSet FOLLOW_29_in_operateur265 = new BitSet(new long[]{0x0000000040103010L});
    public static final BitSet FOLLOW_liste_contraintes_in_operateur272 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_30_in_operateur277 = new BitSet(new long[]{0x000000000000C000L});
    public static final BitSet FOLLOW_15_in_operateur283 = new BitSet(new long[]{0x0000000020100000L});
    public static final BitSet FOLLOW_29_in_operateur286 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_liste_calcul_in_operateur288 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_20_in_operateur295 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_operateur299 = new BitSet(new long[]{0x0000000040000000L});
    public static final BitSet FOLLOW_30_in_operateur304 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_operateur309 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_op_membres322 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_13_in_contrainte_op_membres324 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_op_membres328 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_op_membres330 = new BitSet(new long[]{0x0000000000000800L});
    public static final BitSet FOLLOW_11_in_contrainte_op_membres332 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_contrainte_op_membres336 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_op_membres338 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_op_membres342 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte_op_membres344 = new BitSet(new long[]{0x0000000000000012L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes365 = new BitSet(new long[]{0x0000000000200002L});
    public static final BitSet FOLLOW_21_in_liste_contraintes369 = new BitSet(new long[]{0x0000000000103010L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes373 = new BitSet(new long[]{0x0000000000200002L});
    public static final BitSet FOLLOW_expr_calcul_in_liste_calcul392 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_liste_calcul394 = new BitSet(new long[]{0x0000000000000082L});
    public static final BitSet FOLLOW_contrainte_egal_in_contrainte414 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_adj_in_contrainte422 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_condition_unique_in_contrainte430 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_generale_in_contrainte438 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_13_in_contrainte444 = new BitSet(new long[]{0x0000000000103010L});
    public static final BitSet FOLLOW_contrainte_in_contrainte448 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte451 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_12_in_contrainte_egal464 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal468 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_egal470 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal474 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_contrainte_egal476 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_egal478 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal482 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_egal484 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal488 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_adj502 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_13_in_contrainte_adj504 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_adj506 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj510 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj512 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj516 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj518 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_adj520 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj524 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj526 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj530 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte_adj532 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_12_in_condition_unique552 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_condition_unique556 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_condition_unique558 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_condition_unique562 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_OP_COMP_in_condition_unique566 = new BitSet(new long[]{0x0000000012000100L});
    public static final BitSet FOLLOW_constante_in_condition_unique570 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_20_in_contrainte_generale586 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_contrainte_generale590 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_expr_calcul603 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_expr_calcul605 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_expr_calcul607 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_INT_in_expr_calcul611 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_expr_calcul613 = new BitSet(new long[]{0x0000000000000080L});
    public static final BitSet FOLLOW_ID_in_expr_calcul617 = new BitSet(new long[]{0x0000000000000002L});

}