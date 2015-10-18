#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=superstartrek
PKG_VERSION:=0.0.21-2010
PKG_RELEASE:=1

PKG_SOURCE:=sstsrc.zip
PKG_SOURCE_URL:=http://www.almy.us/files
PKG_MD5SUM:=bd88bb89e8f968b2f8216d2e45792411
PKG_BUILD_DIR:=$(BUILD_DIR)/sstsrc

include $(INCLUDE_DIR)/package.mk

define Package/superstartrek
	SECTION:=games
	CATEGORY:=Games
	TITLE:=A quite possibly the best of the Star Trek games from the 1970s
	URL:=http://www.almy.us/sst.html
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/superstartrek/description
 Super Star Trek is quite possibly the best of the Star Trek games
 from the 1970s. Of course, it does not make use of graphics, or even assume
 a video display, but it still an interesting game to play, particularly for
 those of us who don't have the reflexes we used to and  prefer a more cerebral
 computer game.
endef

define Build/Configure
	rm -fr $(BUILD_DIR)/__MACOSX
endef

define Package/superstartrek/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/sst $(1)/opt/bin
endef

$(eval $(call BuildPackage,superstartrek))
