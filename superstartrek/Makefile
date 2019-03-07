#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=superstartrek
PKG_VERSION:=0.0.21-2015
PKG_RELEASE:=1

PKG_SOURCE:=sstsrc.zip
PKG_SOURCE_URL:=http://www.almy.us/files
PKG_HASH:=2b9b7ca0ef9900caa6c0ba0a34534d5e8f6a95d7c829c8f80719fd3421a4a501

PKG_UNPACK:=unzip -j $(DL_DIR)/$(PKG_SOURCE) -d $(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/superstartrek
	SECTION:=games
	CATEGORY:=Games
	TITLE:=A quite possibly the best of the Star Trek games from the 1970s
	URL:=http://www.almy.us/sst.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/superstartrek/description
 Super Star Trek is quite possibly the best of the Star Trek games
 from the 1970s. Of course, it does not make use of graphics, or even assume
 a video display, but it still an interesting game to play, particularly for
 those of us who don't have the reflexes we used to and  prefer a more cerebral
 computer game.
endef

define Package/superstartrek/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/sst $(1)/opt/bin
endef

$(eval $(call BuildPackage,superstartrek))
