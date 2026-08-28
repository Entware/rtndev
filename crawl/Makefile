# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=crawl
PKG_VERSION:=0.34.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/crawl/crawl.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=1eebc1a2892e1c89776a0d7a10691f8dac8d9796
PKG_MIRROR_HASH:=d278ddafdead1a460696d58372405a7fd3965a3c36e236d09698688773780024

PKG_BUILD_DEPENDS:=python-yaml/host

include $(INCLUDE_DIR)/package.mk

define Package/crawl
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncursesw +libsqlite3 +libstdcpp +zlib
	TITLE:=Dungeon Crawl Stone Soup is a role-playing roguelike game
	URL:=https://crawl.develz.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/crawl/description
 Dungeon Crawl Stone Soup is an open-source, single-player, role-playing
 roguelike game of exploration and treasure-hunting in dungeons filled
 with dangerous and unfriendly monsters in a quest to rescue
 the mystifyingly fabulous Orb of Zot.
endef

MAKE_PATH:=crawl-ref/source

define Build/Configure
	echo $(PKG_VERSION) > $(PKG_BUILD_DIR)/crawl-ref/source/util/release_ver
endef

MAKE_FLAGS += \
	BUILD_LUA=yes \
	prefix=/opt \
	DESTDIR=$(PKG_INSTALL_DIR) \
	DATADIR=/opt/share/crawl/ \
	SAVEDIR=/opt/var/crawl/ \
	NO_TRY_GOLD=yes \
	install

define Package/crawl/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/crawl $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/crawl
	$(CP) $(PKG_INSTALL_DIR)/opt/share/crawl/* $(1)/opt/share/crawl
	$(INSTALL_DIR) $(1)/opt/var/crawl/{morgue,saves}
endef

define Package/crawl/postrm
#!/bin/sh

rm -rf /opt/share/crawl
echo Crawl saves \(~5Mb\) still is in /opt/var/crawl
echo You may delete it manually later.
endef

$(eval $(call BuildPackage,crawl))
