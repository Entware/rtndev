#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cavezofphear
PKG_VERSION:=0.5.1
PKG_RELEASE:=1

PKG_SOURCE:=phear-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://www.x86.no/$(PKG_NAME)
PKG_MD5SUM:=c9b3751dc52d332aaf04cbed4addf7c1

PKG_BUILD_DIR:=$(BUILD_DIR)/phear-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/cavezofphear
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncurses
	TITLE:=CAVEZ of PHEAR is a boulder dash / digger like game
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/cavezofphear/description
 CAVEZ of PHEAR is a boulder dash / digger like game for console / terminals
 using ncurses. The goal of this game is to escape through the caves by
 collecting diamonds and avoid falling stones.
endef

define Package/cavezofphear/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/phear $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/phear/data/levels
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/data/{gover,htext,spgraf,tdesc} $(1)/opt/share/phear/data
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/data/levels/{01..11} $(1)/opt/share/phear/data/levels
endef

$(eval $(call BuildPackage,cavezofphear))
