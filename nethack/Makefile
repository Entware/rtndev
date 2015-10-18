#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Patches and post-inst files taken from http://svn.nslu2-linux.org/svnroot/optware/trunk/sources/nethack/
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nethack
PKG_VERSION:=3.4.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-343-src.tgz
PKG_SOURCE_URL:=@SF/project/nethack/nethack/$(PKG_VERSION)/
PKG_MD5SUM:=21479c95990eefe7650df582426457f9

include $(INCLUDE_DIR)/package.mk

define Package/nethack
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncurses
	TITLE:=NetHack is a single player dungeon exploration game
	URL:=http://www.nethack.org
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/nethack/description
 Unlike many other Dungeons & Dragons-inspired games, the emphasis in
 NetHack is on discovering the detail of the dungeon and not simply killing
 everything in sight - in fact, killing everything in sight is a good way
 to die quickly.
endef

define Build/Configure
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.top $(PKG_BUILD_DIR)/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.dat $(PKG_BUILD_DIR)/dat/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.doc $(PKG_BUILD_DIR)/doc/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.src $(PKG_BUILD_DIR)/src/Makefile
	$(CP) $(PKG_BUILD_DIR)/sys/unix/Makefile.utl $(PKG_BUILD_DIR)/util/Makefile
endef

define Build/Compile
	make install -C $(PKG_BUILD_DIR) \
		CC=$(TARGET_CC) \
		AR=$(TARGET_AR) \
		RANLIB=$(TARGET_RANLIB) \
		CFLAGS="$(TARGET_CPPFLAGS) -I../include" \
		LFLAGS="$(TARGET_LDFLAGS)" \
		PREFIX=$(PKG_INSTALL_DIR)
endef

define Package/nethack/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/nethackdir/nethack.sh $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/nethackdir/{dat,save,util}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/nethackdir/util/{dgn_comp,lev_comp,makedefs} $(1)/opt/share/nethackdir/util
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/nethackdir/{nethack,recover} $(1)/opt/share/nethackdir
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/nethackdir/dat/* $(1)/opt/share/nethackdir/dat
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/nethackdir/{cmdhelp,data,Guidebook.txt,help,hh,history,license,logfile,opthelp,options,oracles,perm,record,rumors,wizhelp} $(1)/opt/share/nethackdir
endef

define Package/nethack/postinst
#!/bin/sh 
#
# $Id: postinst 4954 2007-01-01 18:02:58Z marceln $

cd /opt/share/nethackdir/dat
../util/dgn_comp dungeon.pdf
../util/lev_comp bigroom.des
../util/lev_comp castle.des
../util/lev_comp endgame.des
../util/lev_comp gehennom.des
../util/lev_comp knox.des
../util/lev_comp medusa.des
../util/lev_comp mines.des
../util/lev_comp oracle.des
../util/lev_comp sokoban.des
../util/lev_comp tower.des
../util/lev_comp yendor.des
../util/lev_comp Arch.des
../util/lev_comp Barb.des
../util/lev_comp Caveman.des
../util/lev_comp Healer.des
../util/lev_comp Knight.des
../util/lev_comp Monk.des
../util/lev_comp Priest.des
../util/lev_comp Ranger.des
../util/lev_comp Rogue.des
../util/lev_comp Samurai.des
../util/lev_comp Tourist.des
../util/lev_comp Valkyrie.des
../util/lev_comp Wizard.des
cp *.lev /opt/share/nethackdir/
cp dungeon /opt/share/nethackdir/dungeon
cd /opt/share/nethackdir/util
./makedefs -q
cp /opt/share/nethackdir/dat/quest.dat /opt/share/nethackdir/quest.dat
#
# This should be solved with a sgid games!
#
chmod 777 /opt/share/nethackdir
chmod 777 /opt/share/nethackdir/record
chmod 777 /opt/share/nethackdir/logfile
chmod 777 /opt/share/nethackdir/perm
chmod 1777 /opt/share/nethackdir/save
endef

$(eval $(call BuildPackage,nethack))
