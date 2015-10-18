#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tty-solitaire
PKG_VERSION:=0.2.0
PKG_REV:=343a55ca1b17cd97cc0393c87a56647c8d23ce2d
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/mpereira/tty-solitaire
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/tty-solitaire
	SECTION:=games
	CATEGORY:=Games
	TITLE:=klondlike solitaire game
	DEPENDS:=libncursesw
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/tty-solitaire/description
 klondlike solitaire game.
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include/ncursesw

define Package/tty-solitaire/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ttysolitaire $(1)/opt/bin/
endef

$(eval $(call BuildPackage,tty-solitaire))
