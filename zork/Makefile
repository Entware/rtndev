# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#
# Abandoned in 2018

include $(TOPDIR)/rules.mk

PKG_NAME:=zork
PKG_VERSION:=1.0-20180131
PKG_REV:=95cd009d235ea921b1c1f70e1a2f6b9e335aa37c
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/brhamon/zork.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=368e1d555245d57648bb36c3cd2c68a0a6aa40d8ff6d09af704720a47a1c0e0a

include $(INCLUDE_DIR)/package.mk

define Package/zork
	SECTION:=games
	CATEGORY:=Games
	TITLE:=Zork (also named as Dungeon) is a text adventure game
	URL:=http://richelbilderbeek.nl/GameZork.htm
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/zork/description
 Zork (also named as Dungeon) is a text adventure game written by
 Tim Anderson, Marc Blank, Bruce Daniels, and Dave Lebling in 1980.
endef

MAKE_FLAGS += LIBS="$(TARGET_LDFLAGS)"

define Build/Compile
	$(CP) ./files/uudecode.c  $(PKG_BUILD_DIR)
	$(HOSTCC) -o $(PKG_BUILD_DIR)/uudecode $(PKG_BUILD_DIR)/uudecode.c
	$(call Build/Compile/Default)
endef

define Package/zork/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dungeon $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/zork
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/dtextc.dat $(1)/opt/share/zork
	$(INSTALL_DIR) $(1)/opt/var
endef

$(eval $(call BuildPackage,zork))
