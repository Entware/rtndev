#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Partially taken from https://github.com/pdf/openwrt-14.07-x86_64-packages/tree/master/net/redis

include $(TOPDIR)/rules.mk

PKG_NAME:=redis
PKG_VERSION:=4.0.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://download.redis.io/releases
PKG_HASH:=769b5d69ec237c3e0481a262ff5306ce30db9b5c8ceb14d1023491ca7be5f6fa

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/redis
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=database
	TITLE:=in-memory key-value cache and store
	DEPENDS:=+libatomic +libpthread
	URL:=http://redis.io/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/redis/description
 Redis is an open source (BSD licensed), in-memory data structure store,
 used as database, cache and message broker.
endef

MAKE_FLAGS += \
	MALLOC="libc" \
	PREFIX="$(PKG_INSTALL_DIR)/opt"

TARGET_LDFLAGS += -ldl -latomic

define Build/Compile
	sed -e 's#^\(REAL_CFLAGS.* \)$$$$(ARCH)#\1#g' -i $(PKG_BUILD_DIR)/deps/hiredis/Makefile
	$(call Build/Compile/Default,-C $(PKG_BUILD_DIR)/deps hiredis linenoise lua PLAT=linux)
	$(call Build/Compile/Default)
endef

define Package/redis/conffiles
/opt/etc/redis.conf
endef

define Package/redis/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/redis* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/redis.conf $(1)/opt/etc
	$(INSTALL_BIN) ./files/S70redis $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,redis))
