#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=alaya
PKG_VERSION:=4.5
PKG_REV:=00c9d13732ee48d2020bebe14329532c06d2a02d
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ColumPaget/Alaya.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=e9807a9defe042afb8ebc70854bdd7c1d48c576c78cacb019e1fd08959c0f225

PKG_FIXUP:=autoreconf
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
