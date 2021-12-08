#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tty-solitaire
PKG_VERSION:=1.3.1
PKG_REV:=4875f34e6bbdb6e975bdcedefd5c1d0acf6e19e5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/mpereira/tty-solitaire.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=69f4df139f30aae1d21583cb0954081a5a1b417ac1b6bc23324a162c5ca24aba

include $(INCLUDE_DIR)/package.mk

define Package/tty-solitaire
	SECTION:=games
	CATEGORY:=Games
	TITLE:=klondlike solitaire game
	DEPENDS:=libncursesw
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/tty-solitaire/description
 klondlike solitaire game.
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include/ncursesw

define Package/tty-solitaire/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ttysolitaire $(1)/opt/bin
endef

$(eval $(call BuildPackage,tty-solitaire))
