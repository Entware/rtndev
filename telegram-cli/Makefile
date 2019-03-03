#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=telegram-cli
PKG_VERSION:=1.3.1-20160323
PKG_REV:=6547c0b21b977b327b3c5e8142963f4bc246187a
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/vysheng/tg
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_REMOVE_FILES:=ax_lua.m4
PKG_FIXUP:=autoreconf

PKG_BUILD_DEPENDS:=telegram-cli/host

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/telegram-cli
	SUBMENU:=Instant Messaging
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libconfig +libopenssl +libreadline +libevent2 +jansson \
	    +libpthread +libncursesw +liblua
	TITLE:=CLI for Telegram
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/telegram-cli/description
 Telegram messenger command-line interface
endef

HOST_CONFIGURE_ARGS += \
	--disable-python \
	--disable-valgrind

CONFIGURE_ARGS += \
	--disable-python \
	--disable-valgrind \
	--with-zlib=$(STAGING_DIR)/opt

CONFIGURE_VARS += \
	LIBS=-lncursesw \
	LUA_INCLUDE="-I$(STAGING_DIR)/opt/include" \
	LUA_LIB="-L$(STAGING_DIR)/opt/lib -llua"

define Host/Configure
	(cd $(HOST_BUILD_DIR)/tgl; \
	./configure; \
	)
endef

define Host/Compile
	$(MAKE) $(HOST_JOBS) -C $(HOST_BUILD_DIR)/tgl $(HOST_MAKE_FLAGS)
endef

define Host/Install
endef

define Build/Compile
	mkdir -p $(PKG_BUILD_DIR)/bin
	$(CP) $(HOST_BUILD_DIR)/tgl/bin/*  $(PKG_BUILD_DIR)/bin
	$(call Build/Compile/Default)
endef

define Package/telegram-cli/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bin/telegram-cli $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/telegram-cli
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/tg-server.pub $(1)/opt/etc/telegram-cli
endef

define Package/telegram-cli/postinst
#!/bin/sh

echo 'Warning! Requires 256MB + 256MB SWAP to start, ~100MB of RAM while running.'
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,telegram-cli))
