#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pixelserv-tls
PKG_VERSION:=2.2.1
PKG_REV:=1a865556288be274dae0f54a17f26260740d9a56
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/kvic-z/pixelserv-tls.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/pixelserv-tls
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	DEPENDS:=+libopenssl +libpthread
	TITLE:=one pixel webserver
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pixelserv-tls/description
 pixelserv-tls is a tiny bespoke webserver for adblock
 with HTTP/1.1 and HTTPS support
endef

define Build/Compile
	$(TARGET_CC) \
		$(TARGET_CPPFLAGS) -DDROP_ROOT -DIF_MODE -DUSE_PTHREAD \
		$(TARGET_LDFLAGS) -lssl -lcrypto -lpthread \
		$(PKG_BUILD_DIR)/util.c \
		$(PKG_BUILD_DIR)/socket_handler.c \
		$(PKG_BUILD_DIR)/pixelserv.c \
		$(PKG_BUILD_DIR)/certs.c \
		$(PKG_BUILD_DIR)/logger.c \
		-o $(PKG_BUILD_DIR)/pixelserv-tls
endef

define Package/pixelserv-tls/postinst
#!/bin/sh
cat << EOF
Place ca.crt and ca.key to /opt/var/cache/pixelserv before starting HTTPS mode.
Start options can be adjusted via /opt/etc/init.d/S80pixelserv-tls.

See 'pixelserv-tls -h' for details
EOF
endef

define Package/pixelserv-tls/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pixelserv-tls $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S80pixelserv-tls $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/cache/pixelserv
endef

$(eval $(call BuildPackage,pixelserv-tls))
