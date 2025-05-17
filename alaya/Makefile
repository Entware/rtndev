# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=alaya
PKG_VERSION:=4.6
PKG_REV:=30fbc24676957c6e836c9865dc364f6dbde974c4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ColumPaget/Alaya.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=eade9b15d45f8c177a3cd80b3339abc4ffd94a8e9192fea692a076fd90dc9bd3

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/alaya
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	TITLE:=A WEBDAV Server
	URL:=https://sites.google.com/site/columscode/home/Alaya
	DEPENDS:=+libopenssl +libcap +libpam
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/alaya/description
 A webdav enabled webserver mostly focused on file storage.
endef

CONFIGURE_ARGS += \
	--enable-xattr \
	--enable-capabilities=no \
	--enable-ssl \
	--enable-ip6 \
	--enable-pam

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include

TARGET_LDFLAGS += \
	-lssl -lcrypto

define Package/alaya/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/alaya $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/alaya.conf $(1)/opt/etc
	$(INSTALL_BIN) files/S80alaya $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,alaya))
