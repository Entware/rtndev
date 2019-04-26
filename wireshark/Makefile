#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=wireshark
PKG_VERSION:=3.0.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://wireshark.org/download/src
PKG_HASH:=86864c3d0f6c2311992a98d8ea7dfd429097fe62dae2e5516e1a2f6bef2ac08c

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/wireshark
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libcares +bcg729 +libcap +libgcrypt +glib2 +libgnutls +krb5-libs +libnghttp2 +libpcap +sbc +libspandsp +libxml2
	TITLE:=network protocol analyzer
	URL:=https://www.wireshark.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/wireshark/description
 Wireshark is the world’s foremost and widely-used network protocol analyzer.
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include/krb

CMAKE_OPTIONS += \
	-DBUILD_wireshark=OFF \
	-DENABLE_LUA=OFF

define Build/Compile
	touch $(PKG_BUILD_DIR)/tools/lemon/CMakeFiles/lemon.dir/lemon.c.o
	$(HOSTCC) $(PKG_BUILD_DIR)/tools/lemon/lemon.c \
		-o $(PKG_BUILD_DIR)/run/lemon
	$(call Build/Compile/Default)
endef

define Package/wireshark/install
	$(INSTALL_DIR) $(1)/opt/lib/wireshark
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/wireshark/{extcap,plugins} \
		$(1)/opt/lib/wireshark
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/wireshark $(1)/opt/share
endef

$(eval $(call BuildPackage,wireshark))
