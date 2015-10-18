#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=zork
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_SOURCE:=GameZorkSource_1_0.zip
PKG_SOURCE_URL:=http://richelbilderbeek.nl
PKG_MD5SUM:=9b5a9f1717b467ae4e32e0a2a70ddde7

PKG_UNPACK=unzip -d  $(PKG_BUILD_DIR) $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk

define Package/zork
	SECTION:=games
	CATEGORY:=Games
	TITLE:=Zork (also named as Dungeon) is a text adventure game
	URL:=http://richelbilderbeek.nl/GameZork.htm
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/zork/description
 Zork (also named as Dungeon) is a text adventure game written by
 Tim Anderson, Marc Blank, Bruce Daniels, and Dave Lebling in 1980.
endef

define Build/Configure
	cd $(PKG_BUILD_DIR); \
	for srcfile in `ls -1 *.C`; do \
		if [ ! -f $$$$srcfile ]; then \
			continue; \
		fi; \
		lc=`echo $$$$srcfile | tr '[A-Z]' '[a-z]'`; \
		if [ $$$$lc != $$$$srcfile ]; then \
			mv -i $$$$srcfile $$$$lc; \
		fi; \
	done;
	cat $(PKG_BUILD_DIR)/MAKEFILE_original | tr "\032" "\n" > $(PKG_BUILD_DIR)/Makefile
endef

MAKE_FLAGS += LIBS="$(TARGET_LDFLAGS)"

define Package/zork/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dungeon $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/zork
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/dtextc.dat $(1)/opt/share/zork
	$(INSTALL_DIR) $(1)/opt/var
endef

$(eval $(call BuildPackage,zork))
