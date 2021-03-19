#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vitetris
PKG_VERSION:=0.59.1
PKG_REV:=9bbea4f5ab35d6fb8fe70c14daba19e7f35ab44e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/vicgeralds/vitetris.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=add340e2495083e68d3cf86621f4205575848142a1716554ca5f1a68a041bcd6

include $(INCLUDE_DIR)/package.mk

define Package/vitetris
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncurses
	TITLE:=Terminal-based Tetris clone
	URL:=http://www.victornils.net/tetris
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/vitetris/description
 Vitetris is a terminal-based Tetris clone by Victor Nilsson. Gameplay is
 much like the early Tetris games by Nintendo. Features include:
 configurable keys, highscore table, two-player mode with garbage,
 network play.
endef

define Build/Configure
	cd $(PKG_BUILD_DIR); \
	CC="$(TARGET_CC)" \
	CFLAGS="$(TARGET_CFLAGS)" \
	CPPFLAGS="$(TARGET_CPPFLAGS)" \
	LDFLAGS="$(TARGET_LDFLAGS)" \
	./configure \
		--prefix=$(PKG_INSTALL_DIR) \
		--without-joystick \
		--without-xlib \
		--with-curses
endef

define Package/vitetris/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tetris $(1)/opt/bin/vitetris
endef

$(eval $(call BuildPackage,vitetris))
