#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nethack
PKG_VERSION:=3.6.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-361-src.tgz
PKG_SOURCE_URL:=@SF/project/nethack/nethack/$(PKG_VERSION)
PKG_HASH:=4b8cbf1cc3ad9f6b9bae892d44a9c63106d44782a210906162a7c3be65040ab6

PKG_INSTALL:=1
PKG_BUILD_DEPENDS:=nethack/host

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/nethack
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncurses
	TITLE:=NetHack is a single player dungeon exploration game
	URL:=http://www.nethack.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nethack/description
 Unlike many other Dungeons & Dragons-inspired games, the emphasis in
 NetHack is on discovering the detail of the dungeon and not simply killing
 everything in sight - in fact, killing everything in sight is a good way
 to die quickly.
endef

TARGET_CFLAGS += \
	$(TARGET_CPPFLAGS) \
	-I../include \

MAKE_VARS += \
	LFLAGS="$(TARGET_LDFLAGS) -lncurses" \
	LINK="$(TARGET_CC)" \
	PREFIX="$(PKG_INSTALL_DIR)/opt" \
	HACKDIR="/opt/share/nethackdir" \
	SHELLDIR="$(PKG_INSTALL_DIR)/opt/bin" \
	INSTDIR="$(PKG_INSTALL_DIR)/opt/share/nethackdir" \
	VARDIR="$(PKG_INSTALL_DIR)/opt/share/nethackdir" \
	CHOWN=true \
	CHGRP=true \

define Host/Patch
endef

define Host/Configure
	$(CP) $(HOST_BUILD_DIR)/sys/unix/Makefile.utl $(HOST_BUILD_DIR)/util/Makefile
endef

define Host/Compile
	touch $(HOST_BUILD_DIR)/src/{config,hack}.h-t
	make -C $(HOST_BUILD_DIR)/util makedefs \
		CFLAGS="$(HOST_CPPFLAGS) -I../include"
	(cd $(HOST_BUILD_DIR)/util; ./makedefs -v; ./makedefs -p; ./makedefs -o)
	make -C $(HOST_BUILD_DIR)/util dgn_comp lev_comp \
		CFLAGS="$(HOST_CPPFLAGS) -I../include"
endef

define Host/Install
endef

define Build/Configure
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.top $(PKG_BUILD_DIR)/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.dat $(PKG_BUILD_DIR)/dat/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.doc $(PKG_BUILD_DIR)/doc/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.src $(PKG_BUILD_DIR)/src/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.utl $(PKG_BUILD_DIR)/util/Makefile
	$(LN) $(HOST_BUILD_DIR)/util/makedefs $(PKG_BUILD_DIR)/util/makedefs.host
	$(LN) $(HOST_BUILD_DIR)/util/dgn_comp $(PKG_BUILD_DIR)/util/dgn_comp.host
	$(LN) $(HOST_BUILD_DIR)/util/lev_comp $(PKG_BUILD_DIR)/util/lev_comp.host
endef

define Package/nethack/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/nethack $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/nethackdir $(1)/opt/share
	$(RM) $(1)/opt/share/nethackdir/*.lev
	$(INSTALL_DIR) $(1)/opt/share/nethackdir/dat
	$(CP) $(PKG_BUILD_DIR)/dat/{*.des,dungeon.def,oracles.txt,rumors*,quest.txt} \
		$(1)/opt/share/nethackdir/dat
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/sys/unix/sysconf $(1)/opt/share/nethackdir
	$(INSTALL_DIR) $(1)/opt/share/nethackdir/util
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/util/{dgn_comp,lev_comp,makedefs} \
		$(1)/opt/share/nethackdir/util
endef

define Package/nethack/postinst
#!/bin/sh

cd /opt/share/nethackdir
echo 'Compiling levels...'
for level in dat/*.des; do
        ./util/lev_comp $$level
done
cd util
echo 'Generating dungeon.pdf...'
../util/makedefs -e
echo 'Generating quest.dat...'
../util/makedefs -q
mv -f ../dat/quest.dat ..
echo 'Generating rumors file...'
../util/makedefs -r
mv -f ../dat/rumors ..
echo 'Generating oracles file...'
../util/makedefs -h
mv -f ../dat/oracles ..
echo 'Compiling dungeon file...'
../util/dgn_comp ../dat/dungeon.pdf
mv -f ../dat/dungeon ..
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,nethack))
