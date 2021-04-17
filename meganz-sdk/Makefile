#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# megacmd must be linked against proper sdk version

include $(TOPDIR)/rules.mk

PKG_NAME:=meganz-sdk
PKG_VERSION:=3.7.3h
PKG_REV:=0e79b2739f695d08efed5a61bbf44362e127c30b
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/meganz/sdk.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8786578776f354c43d38bb9d125642b52fa671bf73a180240ad5720cbe739e56

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/meganz-sdk/Default
	TITLE:=MEGA Client Access Engine
	URL:=https://github.com/meganz/sdk
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libmega
	$(call Package/meganz-sdk/Default)
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libcares +libcryptopp +libcurl +libfuse +libmediainfo \
		+libncursesw +libreadline +libsodium +libsqlite3 +libuv
	TITLE+= (library)
endef

define Package/meganz-sdk
	$(call Package/meganz-sdk/Default)
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libmega
	TITLE+= (utility)
endef

define Package/libmega/description
 MEGA SDK - Client Access Engine (library).
endef

define Package/meganz-sdk/description
 MEGA SDK - Client Access Engine (utility).
endef

CONFIGURE_ARGS += \
	--disable-doxygen-doc \
	--without-freeimage \
	--with-cryptopp=$(STAGING_DIR)/opt \
	--with-libuv=$(STAGING_DIR)/opt \
	--with-ffmpeg=$(STAGING_DIR)/opt

TARGET_LDFLAGS += \
	-lpthread

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/include $(1)/opt
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libmega.pc $(1)/opt/lib/pkgconfig
endef

define Package/libmega/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib
endef

define Package/meganz-sdk/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,libmega))
$(eval $(call BuildPackage,meganz-sdk))
