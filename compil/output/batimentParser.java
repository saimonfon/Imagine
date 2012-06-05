// $ANTLR 3.4 C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g 2012-06-01 15:43:17

import java.util.LinkedList;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class batimentParser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "ADJ", "CONST", "EXPONENT", "FLOAT", "ID", "INT", "WS", "'#'", "'$'", "'('", "')'", "','", "'->'", "'.'", "';'", "'='", "'=='", "'@'", "'^'", "'cycle('", "'grammaire'", "'sequence('", "'{'", "'}'"
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
    public static final int ADJ=4;
    public static final int CONST=5;
    public static final int EXPONENT=6;
    public static final int FLOAT=7;
    public static final int ID=8;
    public static final int INT=9;
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


    // $ANTLR start "grammaire"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:11:1: grammaire : dinclude dnom= def_nom def_regles ;
    public final void grammaire() throws RecognitionException {
        String dnom =null;


        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:12:2: ( dinclude dnom= def_nom def_regles )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:12:4: dinclude dnom= def_nom def_regles
            {
            System.out.println("#include \"Parser.h\"");
            System.out.println("#include <vector>");
            System.out.println("#include <string>");
            System.out.println("#include \"regles/RegleStandard.h\"");
            System.out.println("#include \"regles/RegleSequence.h\"");
            System.out.println("#include \"regles/RegleCycle.h\"");
            System.out.println("#include \"condition/ConditionAdj.h\"");
            System.out.println("#include \"condition/ConditionEgal.h\"");
            System.out.println("#include \"regles/CalculAttributs.h\"");

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:29:1: dinclude : ( '#' i= ID )* ;
    public final void dinclude() throws RecognitionException {
        Token i=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:30:2: ( ( '#' i= ID )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:30:4: ( '#' i= ID )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:30:4: ( '#' i= ID )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( (LA1_0==11) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:30:5: '#' i= ID
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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:1: def_nom returns [String nom] : 'grammaire' id= ID ;
    public final String def_nom() throws RecognitionException {
        String nom = null;


        Token id=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:29: ( 'grammaire' id= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:32:31: 'grammaire' id= ID
            {
            match(input,24,FOLLOW_24_in_def_nom68); 

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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:33:1: def_regles : ( regle_stand | regle_seq | regle_cycle )* ;
    public final void def_regles() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:2: ( ( regle_stand | regle_seq | regle_cycle )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:4: ( regle_stand | regle_seq | regle_cycle )*
            {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:4: ( regle_stand | regle_seq | regle_cycle )*
            loop2:
            do {
                int alt2=4;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==ID) ) {
                    int LA2_2 = input.LA(2);

                    if ( (LA2_2==16) ) {
                        switch ( input.LA(3) ) {
                        case 25:
                            {
                            alt2=2;
                            }
                            break;
                        case 23:
                            {
                            alt2=3;
                            }
                            break;
                        case ID:
                            {
                            alt2=1;
                            }
                            break;

                        }

                    }


                }


                switch (alt2) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:5: regle_stand
            	    {
            	    pushFollow(FOLLOW_regle_stand_in_def_regles84);
            	    regle_stand();

            	    state._fsp--;


            	    }
            	    break;
            	case 2 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:17: regle_seq
            	    {
            	    pushFollow(FOLLOW_regle_seq_in_def_regles86);
            	    regle_seq();

            	    state._fsp--;


            	    }
            	    break;
            	case 3 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:34:27: regle_cycle
            	    {
            	    pushFollow(FOLLOW_regle_cycle_in_def_regles88);
            	    regle_cycle();

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



    // $ANTLR start "regle_stand"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:2: regle_stand : i1= ID '->' i2= ID ( ',' i3= ID )* '{' ( liste_contraintes )? '}' '{' ( liste_calcul )? '}' ;
    public final void regle_stand() throws RecognitionException {
        Token i1=null;
        Token i2=null;
        Token i3=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:14: (i1= ID '->' i2= ID ( ',' i3= ID )* '{' ( liste_contraintes )? '}' '{' ( liste_calcul )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:36:16: i1= ID '->' i2= ID ( ',' i3= ID )* '{' ( liste_contraintes )? '}' '{' ( liste_calcul )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_stand102); 

            match(input,16,FOLLOW_16_in_regle_stand104); 


            	System.out.println("vector<string> v"+n+";");

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_stand113); 

            System.out.println("v"+n+".push_back(\""+(i2!=null?i2.getText():null)+"\");");

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:40:2: ( ',' i3= ID )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( (LA3_0==15) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:40:3: ',' i3= ID
            	    {
            	    match(input,15,FOLLOW_15_in_regle_stand119); 

            	    i3=(Token)match(input,ID,FOLLOW_ID_in_regle_stand123); 

            	    System.out.println("v"+n+".push_back(\""+(i3!=null?i3.getText():null)+"\");");

            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            System.out.println("RegleStandard* r"+n+" = new RegleStandard(\""+(i1!=null?i1.getText():null)+"\",v"+n+");");System.out.println("ajouterRegle(r"+n+");");

            match(input,26,FOLLOW_26_in_regle_stand136); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:7: ( liste_contraintes )?
            int alt4=2;
            int LA4_0 = input.LA(1);

            if ( (LA4_0==ADJ||(LA4_0 >= 12 && LA4_0 <= 13)||LA4_0==21) ) {
                alt4=1;
            }
            switch (alt4) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:7: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_stand138);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,27,FOLLOW_27_in_regle_stand140); 

            match(input,26,FOLLOW_26_in_regle_stand143); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:34: ( liste_calcul )?
            int alt5=2;
            int LA5_0 = input.LA(1);

            if ( (LA5_0==ID) ) {
                alt5=1;
            }
            switch (alt5) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:42:35: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_stand146);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;

            }


            match(input,27,FOLLOW_27_in_regle_stand152); 

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
    // $ANTLR end "regle_stand"



    // $ANTLR start "regle_seq"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:2: regle_seq : i1= ID '->' 'sequence(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul )? '}' ;
    public final void regle_seq() throws RecognitionException {
        Token i1=null;
        Token i2=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:12: (i1= ID '->' 'sequence(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:44:14: i1= ID '->' 'sequence(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_seq167); 

            match(input,16,FOLLOW_16_in_regle_seq169); 

            match(input,25,FOLLOW_25_in_regle_seq171); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_seq175); 

            System.out.println("RegleSequence* r"+n+" = new RegleSequence(\""+(i1!=null?i1.getText():null)+"\",\""+(i2!=null?i2.getText():null)+"\");");System.out.println("ajouterRegle(r"+n+");");

            match(input,15,FOLLOW_15_in_regle_seq180); 

            match(input,26,FOLLOW_26_in_regle_seq182); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:10: ( liste_contraintes )?
            int alt6=2;
            int LA6_0 = input.LA(1);

            if ( (LA6_0==ADJ||(LA6_0 >= 12 && LA6_0 <= 13)||LA6_0==21) ) {
                alt6=1;
            }
            switch (alt6) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:10: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_seq184);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,27,FOLLOW_27_in_regle_seq186); 

            match(input,14,FOLLOW_14_in_regle_seq188); 

            match(input,26,FOLLOW_26_in_regle_seq190); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:40: ( liste_calcul )?
            int alt7=2;
            int LA7_0 = input.LA(1);

            if ( (LA7_0==ID) ) {
                alt7=1;
            }
            switch (alt7) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:45:41: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_seq193);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;

            }


            match(input,27,FOLLOW_27_in_regle_seq199); 

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
    // $ANTLR end "regle_seq"



    // $ANTLR start "regle_cycle"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:47:2: regle_cycle : i1= ID '->' 'cycle(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul )? '}' ;
    public final void regle_cycle() throws RecognitionException {
        Token i1=null;
        Token i2=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:47:14: (i1= ID '->' 'cycle(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul )? '}' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:47:16: i1= ID '->' 'cycle(' i2= ID ',' '{' ( liste_contraintes )? '}' ')' '{' ( liste_calcul )? '}'
            {
            i1=(Token)match(input,ID,FOLLOW_ID_in_regle_cycle214); 

            match(input,16,FOLLOW_16_in_regle_cycle216); 

            match(input,23,FOLLOW_23_in_regle_cycle218); 

            i2=(Token)match(input,ID,FOLLOW_ID_in_regle_cycle222); 

            System.out.println("RegleCycle* r"+n+" = new RegleCycle(\""+(i1!=null?i1.getText():null)+"\",\""+(i2!=null?i2.getText():null)+"\");");System.out.println("ajouterRegle(r"+n+");");

            match(input,15,FOLLOW_15_in_regle_cycle227); 

            match(input,26,FOLLOW_26_in_regle_cycle229); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:10: ( liste_contraintes )?
            int alt8=2;
            int LA8_0 = input.LA(1);

            if ( (LA8_0==ADJ||(LA8_0 >= 12 && LA8_0 <= 13)||LA8_0==21) ) {
                alt8=1;
            }
            switch (alt8) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:10: liste_contraintes
                    {
                    pushFollow(FOLLOW_liste_contraintes_in_regle_cycle231);
                    liste_contraintes();

                    state._fsp--;


                    }
                    break;

            }


            match(input,27,FOLLOW_27_in_regle_cycle233); 

            match(input,14,FOLLOW_14_in_regle_cycle235); 

            match(input,26,FOLLOW_26_in_regle_cycle237); 

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:40: ( liste_calcul )?
            int alt9=2;
            int LA9_0 = input.LA(1);

            if ( (LA9_0==ID) ) {
                alt9=1;
            }
            switch (alt9) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:48:41: liste_calcul
                    {
                    pushFollow(FOLLOW_liste_calcul_in_regle_cycle240);
                    liste_calcul();

                    state._fsp--;


                    System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");

                    }
                    break;

            }


            match(input,27,FOLLOW_27_in_regle_cycle246); 

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
    // $ANTLR end "regle_cycle"



    // $ANTLR start "liste_contraintes"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:50:1: liste_contraintes : contrainte ( '^' contrainte )* ;
    public final void liste_contraintes() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:50:51: ( contrainte ( '^' contrainte )* )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:51:2: contrainte ( '^' contrainte )*
            {
            pushFollow(FOLLOW_contrainte_in_liste_contraintes258);
            contrainte();

            state._fsp--;


            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:51:13: ( '^' contrainte )*
            loop10:
            do {
                int alt10=2;
                int LA10_0 = input.LA(1);

                if ( (LA10_0==22) ) {
                    alt10=1;
                }


                switch (alt10) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:51:14: '^' contrainte
            	    {
            	    match(input,22,FOLLOW_22_in_liste_contraintes261); 

            	    pushFollow(FOLLOW_contrainte_in_liste_contraintes263);
            	    contrainte();

            	    state._fsp--;


            	    }
            	    break;

            	default :
            	    break loop10;
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
    // $ANTLR end "liste_contraintes"



    // $ANTLR start "liste_calcul"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:53:1: liste_calcul : ( expr_calcul ';' )+ ;
    public final void liste_calcul() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:54:2: ( ( expr_calcul ';' )+ )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:55:2: ( expr_calcul ';' )+
            {
             System.out.
            	
            	println("class Calcul"+n+" : public CalculAttributs {");System.out.println("void calculAttrib(Noeud* nouveau){");

            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:58:2: ( expr_calcul ';' )+
            int cnt11=0;
            loop11:
            do {
                int alt11=2;
                int LA11_0 = input.LA(1);

                if ( (LA11_0==ID) ) {
                    alt11=1;
                }


                switch (alt11) {
            	case 1 :
            	    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:58:3: expr_calcul ';'
            	    {
            	    pushFollow(FOLLOW_expr_calcul_in_liste_calcul280);
            	    expr_calcul();

            	    state._fsp--;


            	    match(input,18,FOLLOW_18_in_liste_calcul282); 

            	    }
            	    break;

            	default :
            	    if ( cnt11 >= 1 ) break loop11;
                        EarlyExitException eee =
                            new EarlyExitException(11, input);
                        throw eee;
                }
                cnt11++;
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
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:2: contrainte : ( contrainte_egal | contrainte_adj | condition_unique | contrainte_generale | '(' contrainte ')' );
    public final void contrainte() throws RecognitionException {
        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:60:39: ( contrainte_egal | contrainte_adj | condition_unique | contrainte_generale | '(' contrainte ')' )
            int alt12=5;
            switch ( input.LA(1) ) {
            case 12:
                {
                int LA12_1 = input.LA(2);

                if ( (LA12_1==INT) ) {
                    int LA12_5 = input.LA(3);

                    if ( (LA12_5==17) ) {
                        int LA12_6 = input.LA(4);

                        if ( (LA12_6==ID) ) {
                            int LA12_7 = input.LA(5);

                            if ( (LA12_7==19) ) {
                                alt12=1;
                            }
                            else if ( (LA12_7==20) ) {
                                alt12=3;
                            }
                            else {
                                NoViableAltException nvae =
                                    new NoViableAltException("", 12, 7, input);

                                throw nvae;

                            }
                        }
                        else {
                            NoViableAltException nvae =
                                new NoViableAltException("", 12, 6, input);

                            throw nvae;

                        }
                    }
                    else {
                        NoViableAltException nvae =
                            new NoViableAltException("", 12, 5, input);

                        throw nvae;

                    }
                }
                else {
                    NoViableAltException nvae =
                        new NoViableAltException("", 12, 1, input);

                    throw nvae;

                }
                }
                break;
            case ADJ:
                {
                alt12=2;
                }
                break;
            case 21:
                {
                alt12=4;
                }
                break;
            case 13:
                {
                alt12=5;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 12, 0, input);

                throw nvae;

            }

            switch (alt12) {
                case 1 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:61:2: contrainte_egal
                    {
                    pushFollow(FOLLOW_contrainte_egal_in_contrainte297);
                    contrainte_egal();

                    state._fsp--;


                    }
                    break;
                case 2 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:62:2: contrainte_adj
                    {
                    pushFollow(FOLLOW_contrainte_adj_in_contrainte301);
                    contrainte_adj();

                    state._fsp--;


                    }
                    break;
                case 3 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:63:2: condition_unique
                    {
                    pushFollow(FOLLOW_condition_unique_in_contrainte305);
                    condition_unique();

                    state._fsp--;


                    }
                    break;
                case 4 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:64:2: contrainte_generale
                    {
                    pushFollow(FOLLOW_contrainte_generale_in_contrainte309);
                    contrainte_generale();

                    state._fsp--;


                    }
                    break;
                case 5 :
                    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:65:2: '(' contrainte ')'
                    {
                    match(input,13,FOLLOW_13_in_contrainte313); 

                    pushFollow(FOLLOW_contrainte_in_contrainte315);
                    contrainte();

                    state._fsp--;


                    match(input,14,FOLLOW_14_in_contrainte316); 

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
    // $ANTLR end "contrainte"



    // $ANTLR start "contrainte_egal"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:67:2: contrainte_egal : '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final void contrainte_egal() throws RecognitionException {
        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:67:18: ( '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:67:20: '$' i= INT '.' att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            match(input,12,FOLLOW_12_in_contrainte_egal326); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal330); 

            match(input,17,FOLLOW_17_in_contrainte_egal332); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal336); 

            match(input,19,FOLLOW_19_in_contrainte_egal338); 

            match(input,12,FOLLOW_12_in_contrainte_egal340); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_egal344); 

            match(input,17,FOLLOW_17_in_contrainte_egal346); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_egal350); 

            System.out.println("r"+n+"->condEgal.push_back(new ConditionEgal("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

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
    // $ANTLR end "contrainte_egal"



    // $ANTLR start "contrainte_adj"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:68:2: contrainte_adj : ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' ;
    public final void contrainte_adj() throws RecognitionException {
        Token i=null;
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:68:17: ( ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')' )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:68:19: ADJ '(' '$' i= INT '.' att_i= ID ',' '$' j= INT '.' att_j= ID ')'
            {
            match(input,ADJ,FOLLOW_ADJ_in_contrainte_adj360); 

            match(input,13,FOLLOW_13_in_contrainte_adj362); 

            match(input,12,FOLLOW_12_in_contrainte_adj364); 

            i=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj368); 

            match(input,17,FOLLOW_17_in_contrainte_adj370); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj374); 

            match(input,15,FOLLOW_15_in_contrainte_adj376); 

            match(input,12,FOLLOW_12_in_contrainte_adj378); 

            j=(Token)match(input,INT,FOLLOW_INT_in_contrainte_adj382); 

            match(input,17,FOLLOW_17_in_contrainte_adj384); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_contrainte_adj388); 

            match(input,14,FOLLOW_14_in_contrainte_adj390); 

            System.out.println("r"+n+"->condAdj.push_back(new ConditionAdj("+(i!=null?i.getText():null)+",\""+(att_i!=null?att_i.getText():null)+"\","+(j!=null?j.getText():null)+",\""+(att_j!=null?att_j.getText():null)+"\"));");

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
    // $ANTLR end "contrainte_adj"



    // $ANTLR start "condition_unique"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:70:2: condition_unique : '$' i= INT '.' att_i= ID '==' val= CONST ;
    public final void condition_unique() throws RecognitionException {
        Token i=null;
        Token att_i=null;
        Token val=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:70:19: ( '$' i= INT '.' att_i= ID '==' val= CONST )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:70:21: '$' i= INT '.' att_i= ID '==' val= CONST
            {
            System.out.println("class ConditionUnique"+n+" : public ConditionUnique{");
            	System.out.println("bool estVerifiee(Noeud* n){return (bool)(");

            match(input,12,FOLLOW_12_in_condition_unique405); 

            i=(Token)match(input,INT,FOLLOW_INT_in_condition_unique409); 

            match(input,17,FOLLOW_17_in_condition_unique411); 

            att_i=(Token)match(input,ID,FOLLOW_ID_in_condition_unique415); 

            match(input,20,FOLLOW_20_in_condition_unique417); 

            val=(Token)match(input,CONST,FOLLOW_CONST_in_condition_unique421); 

            System.out.print("n->getAttribut(\""+(att_i!=null?att_i.getText():null)+"\"))=="+(val!=null?val.getText():null));
            		System.out.println(";}};");
            		System.out.println("ConditionUnique"+n+"* c"+n+" = new ConditionUnique"+n+"(); c"+n+"->indice = "+(i!=null?i.getText():null)+";");
            	System.out.println("r"+n+"->condUnique.push_back(c"+n+");");

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
    // $ANTLR end "condition_unique"



    // $ANTLR start "contrainte_generale"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:78:2: contrainte_generale : '@' i= ID ;
    public final void contrainte_generale() throws RecognitionException {
        Token i=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:78:21: ( '@' i= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:78:22: '@' i= ID
            {
            match(input,21,FOLLOW_21_in_contrainte_generale433); 

            i=(Token)match(input,ID,FOLLOW_ID_in_contrainte_generale437); 

            System.out.println("r"+n+"->condGen.push_back(new "+(i!=null?i.getText():null)+"());");

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
    // $ANTLR end "contrainte_generale"



    // $ANTLR start "expr_calcul"
    // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:80:2: expr_calcul : att_i= ID '=' '$' j= INT '.' att_j= ID ;
    public final void expr_calcul() throws RecognitionException {
        Token att_i=null;
        Token j=null;
        Token att_j=null;

        try {
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:80:14: (att_i= ID '=' '$' j= INT '.' att_j= ID )
            // C:\\Users\\simon\\Documents\\prog_grammaires\\compil\\batiment.g:80:16: att_i= ID '=' '$' j= INT '.' att_j= ID
            {
            att_i=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul450); 

            match(input,19,FOLLOW_19_in_expr_calcul452); 

            match(input,12,FOLLOW_12_in_expr_calcul454); 

            j=(Token)match(input,INT,FOLLOW_INT_in_expr_calcul458); 

            match(input,17,FOLLOW_17_in_expr_calcul460); 

            att_j=(Token)match(input,ID,FOLLOW_ID_in_expr_calcul464); 

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


 

    public static final BitSet FOLLOW_dinclude_in_grammaire27 = new BitSet(new long[]{0x0000000001000000L});
    public static final BitSet FOLLOW_def_nom_in_grammaire31 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_def_regles_in_grammaire36 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_11_in_dinclude48 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_dinclude52 = new BitSet(new long[]{0x0000000000000802L});
    public static final BitSet FOLLOW_24_in_def_nom68 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_def_nom72 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_regle_stand_in_def_regles84 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_regle_seq_in_def_regles86 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_regle_cycle_in_def_regles88 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_ID_in_regle_stand102 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_stand104 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_stand113 = new BitSet(new long[]{0x0000000004008000L});
    public static final BitSet FOLLOW_15_in_regle_stand119 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_stand123 = new BitSet(new long[]{0x0000000004008000L});
    public static final BitSet FOLLOW_26_in_regle_stand136 = new BitSet(new long[]{0x0000000008203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_stand138 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_stand140 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_26_in_regle_stand143 = new BitSet(new long[]{0x0000000008000100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_stand146 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_stand152 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_regle_seq167 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_seq169 = new BitSet(new long[]{0x0000000002000000L});
    public static final BitSet FOLLOW_25_in_regle_seq171 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_seq175 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_regle_seq180 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_26_in_regle_seq182 = new BitSet(new long[]{0x0000000008203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_seq184 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_seq186 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_regle_seq188 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_26_in_regle_seq190 = new BitSet(new long[]{0x0000000008000100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_seq193 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_seq199 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_regle_cycle214 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_16_in_regle_cycle216 = new BitSet(new long[]{0x0000000000800000L});
    public static final BitSet FOLLOW_23_in_regle_cycle218 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_regle_cycle222 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_regle_cycle227 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_26_in_regle_cycle229 = new BitSet(new long[]{0x0000000008203010L});
    public static final BitSet FOLLOW_liste_contraintes_in_regle_cycle231 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_cycle233 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_regle_cycle235 = new BitSet(new long[]{0x0000000004000000L});
    public static final BitSet FOLLOW_26_in_regle_cycle237 = new BitSet(new long[]{0x0000000008000100L});
    public static final BitSet FOLLOW_liste_calcul_in_regle_cycle240 = new BitSet(new long[]{0x0000000008000000L});
    public static final BitSet FOLLOW_27_in_regle_cycle246 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes258 = new BitSet(new long[]{0x0000000000400002L});
    public static final BitSet FOLLOW_22_in_liste_contraintes261 = new BitSet(new long[]{0x0000000000203010L});
    public static final BitSet FOLLOW_contrainte_in_liste_contraintes263 = new BitSet(new long[]{0x0000000000400002L});
    public static final BitSet FOLLOW_expr_calcul_in_liste_calcul280 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_18_in_liste_calcul282 = new BitSet(new long[]{0x0000000000000102L});
    public static final BitSet FOLLOW_contrainte_egal_in_contrainte297 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_adj_in_contrainte301 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_condition_unique_in_contrainte305 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_contrainte_generale_in_contrainte309 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_13_in_contrainte313 = new BitSet(new long[]{0x0000000000203010L});
    public static final BitSet FOLLOW_contrainte_in_contrainte315 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte316 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_12_in_contrainte_egal326 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal330 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_egal332 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal336 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_contrainte_egal338 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_egal340 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_egal344 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_egal346 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_egal350 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ADJ_in_contrainte_adj360 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_13_in_contrainte_adj362 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_adj364 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj368 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj370 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj374 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_15_in_contrainte_adj376 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_contrainte_adj378 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_contrainte_adj382 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_contrainte_adj384 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_adj388 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_14_in_contrainte_adj390 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_12_in_condition_unique405 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_condition_unique409 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_condition_unique411 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_condition_unique415 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_20_in_condition_unique417 = new BitSet(new long[]{0x0000000000000020L});
    public static final BitSet FOLLOW_CONST_in_condition_unique421 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_21_in_contrainte_generale433 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_contrainte_generale437 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_expr_calcul450 = new BitSet(new long[]{0x0000000000080000L});
    public static final BitSet FOLLOW_19_in_expr_calcul452 = new BitSet(new long[]{0x0000000000001000L});
    public static final BitSet FOLLOW_12_in_expr_calcul454 = new BitSet(new long[]{0x0000000000000200L});
    public static final BitSet FOLLOW_INT_in_expr_calcul458 = new BitSet(new long[]{0x0000000000020000L});
    public static final BitSet FOLLOW_17_in_expr_calcul460 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_ID_in_expr_calcul464 = new BitSet(new long[]{0x0000000000000002L});

}