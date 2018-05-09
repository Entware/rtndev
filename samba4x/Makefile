#
# Copyright (C) 2017
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# more binaries are added to server and client packages

include $(TOPDIR)/rules.mk

PKG_NAME:=samba4x
PKG_VERSION:=4.7.3
PKG_RELEASE:=1

PKG_SOURCE:=samba-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://download.samba.org/pub/samba/stable
PKG_HASH:=06e4152ca1cb803f005e92eb6baedb6cc874998b44ee37c2a7819e77a55bfd2c
PKG_BUILD_DIR:=$(BUILD_DIR)/samba-$(PKG_VERSION)

PKG_LICENSE:=GPL-3.0
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_PARALLEL:=1
PKG_INSTALL:=1
PKG_BUILD_DEPENDS:=heimdal


include $(INCLUDE_DIR)/package.mk
# for $(LINUX_VERSION)
include $(INCLUDE_DIR)/kernel.mk
# for $(VERSION_DIST)
include $(INCLUDE_DIR)/version.mk

define Package/samba4x/Default
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Samba $(PKG_VERSION) SMB/CIFS
  URL:=http://www.samba.org/
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/samba4x-libs
  $(call Package/samba4x/Default)
  TITLE+= libraries
  DEPENDS:= +libcap +libarchive +libpopt +zlib +e2fsprogs +jansson +tdb
endef

define Package/samba4x-server
  $(call Package/samba4x/Default)
  TITLE+= server
  DEPENDS:=+samba4x-libs
endef

define Package/samba4x-client
  $(call Package/samba4x/Default)
  TITLE+= client
  DEPENDS:=+samba4x-libs
endef

define Package/samba4x-net
  $(call Package/samba4x/Default)
  TITLE+= net
  DEPENDS:=+samba4x-libs
endef

define Package/samba4x-server/description
  The Samba software suite is a collection of programs that implements the
  SMB protocol for UNIX systems, allowing you to serve files and printers to
  Windows, NT, OS/2 and DOS clients. This protocol is sometimes also referred
  to as the LanManager or Netbios protocol.
endef

CONFIGURE_VARS += \
	CPP="$(TARGET_CROSS)cpp" \
	NCURSES_CONFIG="$(STAGING_DIR)/host/bin/$(NCURSES_CONFIG_SCRIPTS)" \
	PYTHON="$(STAGING_DIR_HOSTPKG)/bin/python" \
	PYTHON_CONFIG="$(STAGING_DIR_HOSTPKG)/bin/python-config" \
	python_LDFLAGS="" \
	python_LIBDIR=""

MAKE_VARS += \
	PRINTCAP_NAME="/opt/etc/printcap"

CONFIGURE_PREFIX = /opt

CONFIGURE_ARGS = \
		--target=$(GNU_TARGET_NAME) \
		--program-prefix="" \
		--prefix=$(CONFIGURE_PREFIX) \
		--exec-prefix=$(CONFIGURE_PREFIX) \
		--bindir=$(CONFIGURE_PREFIX)/bin \
		--sbindir=$(CONFIGURE_PREFIX)/sbin \
		--libexecdir=$(CONFIGURE_PREFIX)/lib \
		--sysconfdir=/opt/etc \
		--datadir=$(CONFIGURE_PREFIX)/share \
		--localstatedir=/opt/var \
		--mandir=$(CONFIGURE_PREFIX)/man \
		--infodir=$(CONFIGURE_PREFIX)/info

CONFIGURE_ARGS += \
		--hostcc="$(shell which gcc)" \
		--cross-compile \
		--cross-answers="$(PKG_BUILD_DIR)/cache.txt" \
		--disable-avahi \
		--disable-cephfs \
		--disable-cups \
		--disable-fault-handling \
		--disable-glusterfs \
		--disable-iprint \
		--disable-python \
		--disable-rpath \
		--disable-rpath-install \
		--enable-fhs \
		--without-acl-support \
		--without-ads \
		--without-ad-dc \
		--without-automount \
		--without-dnsupdate \
		--without-iconv \
		--without-ldap \
		--without-lttng \
		--without-ntvfs-fileserver \
		--without-pam \
		--without-quotas \
		--without-systemd \
		--without-utmp \
		--without-winbind \
		--nopyc \
		--nopyo
		
#--disable-rpath-private-install		

CONFIGURE_ARGS += \
		--with-lockdir=/opt/var/lock/samba \
		--with-logfilebase=/opt/var/log/samba \
		--with-piddir=/opt/var/run/samba \
		--with-privatedir=/opt/etc/samba \
		--without-dmapi \
		--disable-gnutls \
		--with-relro \
		--with-sendfile-support \
		--without-cluster-support \
		--without-fam \
		--without-gettext \
		--without-pie \
		--without-regedit \
		--with-syslog \
		--bundled-libraries='talloc,com_err,!asn1_compile,!compile_et' \
		--enable-auto-reconfigure
		
CONFIGURE_CMD = ./buildtools/bin/waf

define Build/Configure
	$(CP) ./files/cache.txt $(PKG_BUILD_DIR)/cache.txt;
	echo -e "\nChecking uname sysname type: \"$(VERSION_DIST)\" \
	\nChecking uname release type: \"$(LINUX_VERSION)\" \
	\nChecking uname machine type: \"$(ARCH)\" \
	\nChecking uname version type: \"$(VERSION_DIST) Linux-$(LINUX_VERSION) $(shell date +%Y-%m-%d)\"\n" >> $(PKG_BUILD_DIR)/cache.txt;

	$(call Build/Configure/Default,configure)
endef

TARGET_CFLAGS += \
	-fdata-sections \
	-ffunction-sections

TARGET_LDFLAGS += \
	-Wl,--gc-sections

define Build/Compile
	$(call Build/Compile/Default,-j$(shell nproc))
endef

define Package/samba4x-libs/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/samba/*.so* $(1)/opt/lib
endef

define Package/samba4x-server/install
	$(INSTALL_DIR) $(1)/opt/etc/samba $(1)/opt/etc/init.d
	$(INSTALL_DATA) ./files/smb.conf $(1)/opt/etc/samba
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/examples/smb.conf.default $(1)/opt/etc/samba
	$(INSTALL_BIN) ./files/S91smb $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/{smbd,nmbd} $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{smbpasswd,smbstatus,pdbedit,eventlogadm,profiles} $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/var/{cache,lock,log,run} $(1)/opt/var/lib/samba/private
endef

define Package/samba4x-client/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/smb{client,cacls,cquotas,get,spool,tree} $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/nmblookup $(1)/opt/bin
endef

define Package/samba4x-net/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/net $(1)/opt/bin
endef

define Package/samba4x-server/conffiles
/opt/etc/samba/smb.conf
/opt/etc/samba/smbpasswd
endef

$(eval $(call BuildPackage,samba4x-server))
$(eval $(call BuildPackage,samba4x-client))
$(eval $(call BuildPackage,samba4x-libs))
$(eval $(call BuildPackage,samba4x-net))
