#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libmtp
PKG_VERSION:=1.1.19
PKG_REV:=5364ab578f67b6f56df049e11cae319213b59ccf
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/libmtp/libmtp.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=7c471c5f94db4f4c98e7fe783341d9301c9d2b1d7f15cdc7e44aeb0b1c1ef0f7

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libmtp/Default
	SUBMENU:=Filesystem
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libmtp
	$(call Package/libmtp/Default)
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libgcrypt +libusb-1.0 $(ICONV_DEPENDS)
	TITLE:=a library to access MTP devices
endef

define Package/libmtp-utils
	$(call Package/libmtp/Default)
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libmtp
	TITLE:=libmtp utilities
endef

define Package/libmtp/description
 libmtp implements an MTP initiator, which means it initiate
 MTP sessions with devices. The devices responding are known
 as MTP responders. libmtp runs on something with a USB host
 controller interface, using libusb to access the host controller.
endef

define Package/libmtp-utils/description
 nfs-ls, nfs-cat, nfs-cp console usersapce utilities for accessing NFS shares
 over a network.
endef

CONFIGURE_ARGS += \
	--with-libiconv-prefix=$(ICONV_PREFIX) \
	--with-udev=/opt/lib/udev \
	--disable-configfiles

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/* $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmtp.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libmtp.pc $(1)/opt/lib/pkgconfig
endef

define Package/libmtp/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmtp.so* $(1)/opt/lib
endef

define Package/libmtp-utils/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mtp-* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/udev
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/udev/mtp-probe $(1)/opt/lib/udev
endef

$(eval $(call BuildPackage,libmtp))
$(eval $(call BuildPackage,libmtp-utils))
