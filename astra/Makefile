#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=astra
PKG_VERSION:=4.4.187
PKG_REV:=3a3d837f45bea720b40f0c2c074289463bce053a
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://bitbucket.org/cesbo/astra.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/astra
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=advanced streamer
	DEPENDS:=+libopenssl
	URL:=https://cesbo.com/en/astra/
endef

define Package/astra/description
 Astra is a software to organize Digital TV Broadcasting Service.
endef

define Build/Configure
	cd $(PKG_BUILD_DIR); \
	./configure.sh \
		--cc="$(TARGET_CC)" \
		--cflags="$(TARGET_CFLAGS) $(EXTRA_CFLAGS) $(TARGET_CPPFLAGS) $(EXTRA_CPPFLAGS)" \
		--ldflags="$(TARGET_LDFLAGS) -lssl -lcrypto"
endef

define Package/astra/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/astra $(1)/opt/bin/astra
endef

$(eval $(call BuildPackage,astra))
