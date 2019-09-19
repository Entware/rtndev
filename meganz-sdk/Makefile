#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=meganz-sdk
PKG_VERSION:=3.6.2b
PKG_REV:=529437ad0d3bb4be87dd3a259694be53c06278a7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/meganz/sdk.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/meganz-sdk
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libcares +libcryptoxx +libcurl +libfuse +libreadline \
		+libncursesw +libsodium +libsqlite3 +libuv
	TITLE:=MEGA Client Access Engine
	URL:=https://github.com/meganz/sdk
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/meganz-sdk/description
 MEGA SDK - Client Access Engine.
endef

CONFIGURE_ARGS += \
	--disable-doxygen-doc \
	--without-freeimage \
	--with-libuv=$(STAGING_DIR)/opt \
	--with-ffmpeg=$(STAGING_DIR)/opt

TARGET_LDFLAGS += \
	-lpthread

define Package/meganz-sdk/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,meganz-sdk))
