#############################################################################
# Makefile for building: prog_grammaires
# Generated by qmake (2.01a) (Qt 4.8.2) on: lun. 2. juil. 12:02:28 2012
# Project:  prog_grammaires.pro
# Template: app
# Command: c:/Qt/4.8.2/bin/qmake.exe -o Makefile prog_grammaires.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = c:/Qt/4.8.2/bin/qmake.exe
DEL_FILE      = rm
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = cp -r
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: prog_grammaires.pro  ../../../../Qt/4.8.2/mkspecs/default/qmake.conf ../../../../Qt/4.8.2/mkspecs/qconfig.pri \
		../../../../Qt/4.8.2/mkspecs/modules/qt_webkit_version.pri \
		../../../../Qt/4.8.2/mkspecs/features/qt_functions.prf \
		../../../../Qt/4.8.2/mkspecs/features/qt_config.prf \
		../../../../Qt/4.8.2/mkspecs/win32-g++/qmake.conf \
		../../../../Qt/4.8.2/mkspecs/win32-g++-4.6/qmake.conf \
		../../../../Qt/4.8.2/mkspecs/features/exclusive_builds.prf \
		../../../../Qt/4.8.2/mkspecs/features/default_pre.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/default_pre.prf \
		../../../../Qt/4.8.2/mkspecs/features/debug.prf \
		../../../../Qt/4.8.2/mkspecs/features/debug_and_release.prf \
		../../../../Qt/4.8.2/mkspecs/features/default_post.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/default_post.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/console.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/rtti.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/exceptions.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/stl.prf \
		../../../../Qt/4.8.2/mkspecs/features/shared.prf \
		../../../../Qt/4.8.2/mkspecs/features/warn_on.prf \
		../../../../Qt/4.8.2/mkspecs/features/qt.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/opengl.prf \
		../../../../Qt/4.8.2/mkspecs/features/win32/thread.prf \
		../../../../Qt/4.8.2/mkspecs/features/moc.prf \
		../../../../Qt/4.8.2/mkspecs/features/resources.prf \
		../../../../Qt/4.8.2/mkspecs/features/uic.prf \
		../../../../Qt/4.8.2/mkspecs/features/yacc.prf \
		../../../../Qt/4.8.2/mkspecs/features/lex.prf \
		../../../../Qt/4.8.2/mkspecs/features/include_source_dir.prf
	$(QMAKE) -o Makefile prog_grammaires.pro
../../../../Qt/4.8.2/mkspecs/qconfig.pri:
../../../../Qt/4.8.2/mkspecs/modules/qt_webkit_version.pri:
../../../../Qt/4.8.2/mkspecs/features/qt_functions.prf:
../../../../Qt/4.8.2/mkspecs/features/qt_config.prf:
../../../../Qt/4.8.2/mkspecs/win32-g++/qmake.conf:
../../../../Qt/4.8.2/mkspecs/win32-g++-4.6/qmake.conf:
../../../../Qt/4.8.2/mkspecs/features/exclusive_builds.prf:
../../../../Qt/4.8.2/mkspecs/features/default_pre.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/default_pre.prf:
../../../../Qt/4.8.2/mkspecs/features/debug.prf:
../../../../Qt/4.8.2/mkspecs/features/debug_and_release.prf:
../../../../Qt/4.8.2/mkspecs/features/default_post.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/default_post.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/console.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/rtti.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/exceptions.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/stl.prf:
../../../../Qt/4.8.2/mkspecs/features/shared.prf:
../../../../Qt/4.8.2/mkspecs/features/warn_on.prf:
../../../../Qt/4.8.2/mkspecs/features/qt.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/opengl.prf:
../../../../Qt/4.8.2/mkspecs/features/win32/thread.prf:
../../../../Qt/4.8.2/mkspecs/features/moc.prf:
../../../../Qt/4.8.2/mkspecs/features/resources.prf:
../../../../Qt/4.8.2/mkspecs/features/uic.prf:
../../../../Qt/4.8.2/mkspecs/features/yacc.prf:
../../../../Qt/4.8.2/mkspecs/features/lex.prf:
../../../../Qt/4.8.2/mkspecs/features/include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -o Makefile prog_grammaires.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
