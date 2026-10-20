#
# Copyright (C) 2011-2026 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Slightly modified Openwrt package by Yousong Zhou
#

include $(TOPDIR)/rules.mk

# Checklist when bumping versions
#
# - update cipher list by checking src/crypto.c:crypto_init()
# - check if default mode has changed from being tcp_only
#
PKG_NAME:=shadowsocks-libev
PKG_VERSION:=3.3.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/shadowsocks/shadowsocks-libev.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=c5e8788013a37afe54ea1c2b7c03395cccc663cf
PKG_SOURCE_SUBMODULES:=libcork libipset libbloom
PKG_MIRROR_HASH:=eeece36c497f8b72c3038cab9b0bc11e00329ab5b7dfe955be9c16530eb9d799

PKG_MAINTAINER:=Yousong Zhou <yszhou4tech@gmail.com>

PKG_LICENSE:=GPL-3.0-or-later
PKG_LICENSE_FILES:=LICENSE
PKG_CPE_ID:=cpe:/a:shadowsocks:shadowsocks-libev

PKG_INSTALL:=1
PKG_BUILD_FLAGS:=no-mips16 lto
PKG_BUILD_PARALLEL:=1
PKG_BUILD_DEPENDS:=c-ares pcre2

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk


define Package/shadowsocks-libev-config
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web Servers/Proxies
  TITLE:=shadowsocks-libev config scripts
  URL:=https://github.com/shadowsocks/shadowsocks-libev
endef

define Package/shadowsocks-libev-config/conffiles
/opt/etc/shadowsocks.json
endef

define Package/shadowsocks-libev-config/install
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/debian/config.json $(1)/opt/etc/shadowsocks.json
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S22shadowsocks $(1)/opt/etc/init.d
endef


define Package/shadowsocks-libev/Default
  define Package/shadowsocks-libev-$(1)
    SECTION:=net
    CATEGORY:=Network
    SUBMENU:=Web Servers/Proxies
    TITLE:=shadowsocks-libev $(1)
    URL:=https://github.com/shadowsocks/shadowsocks-libev
    DEPENDS:=+libev +libmbedtls +libpthread +libsodium +shadowsocks-libev-config $(DEPENDS_$(1)) +zlib
  endef

  define Package/shadowsocks-libev-$(1)/install
	$$(INSTALL_DIR) $$(1)/opt/bin
	$$(INSTALL_BIN) $$(PKG_INSTALL_DIR)/opt/bin/$(1) $$(1)/opt/bin
  endef

endef

DEPENDS_ss-local = +libpcre2
DEPENDS_ss-server = +libcares +libpcre2

SHADOWSOCKS_COMPONENTS:=ss-local ss-redir ss-tunnel ss-server
define shadowsocks-libev/templates
  $(foreach component,$(SHADOWSOCKS_COMPONENTS),
    $(call Package/shadowsocks-libev/Default,$(component))
  )
endef
$(eval $(call shadowsocks-libev/templates))


define Build/Prepare
	$(call Build/Prepare/Default)
	$(FIND) $(PKG_BUILD_DIR) \
			   -name '*.o' \
			-o -name '*.lo' \
			-o -name '.deps' \
			-o -name '.libs' \
		| $(XARGS) rm -rvf
endef

CMAKE_OPTIONS += \
	-DWITH_STATIC=OFF \
	-DWITH_DOC_MAN=OFF \
	-DWITH_DOC_HTML=OFF \
	-DBUILD_TESTING=OFF

TARGET_LDFLAGS += -Wl,--gc-sections,--as-needed

$(eval $(call BuildPackage,shadowsocks-libev-config))
$(foreach component,$(SHADOWSOCKS_COMPONENTS), \
  $(eval $(call BuildPackage,shadowsocks-libev-$(component))) \
)
